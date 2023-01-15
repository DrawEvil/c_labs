#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void strip(char* s) {
    int len, i, pos;

    len = strlen(s);
    for (i = 0; i < len && isspace(s[i]); ++i) {}
    for (pos = 0; i < len; ++i, ++pos) {
        s[pos] = s[i];
    }
    s[pos] = '\0';
    for (i = pos - 1; i >= 0 && isspace(s[i]); --i) {}
    s[i + 1] = '\0';
}

void strcut(char* s, int len) {
    s[len] = '\0';
}

char* myGets(char* dst, int maxcount) {
    char buffer[128];
    do {
        fgets(buffer, 128, stdin);
        strip(buffer);
    } while (strlen(buffer) == 0);
    strcut(buffer, maxcount);
    strcpy(dst, buffer);
    return dst;
}


typedef struct Hotel_ {
    char name[32];
    int stars;
    char address[64];
    char phone[20];
    int rooms;
    int lux_rooms;
    int free_rooms;
} Hotel;

void inputHotel(Hotel* hotel) {
    printf("Name       -> ");
    myGets(hotel->name, 32);
    printf("Stars      -> ");
    scanf("%d", &hotel->stars);
    printf("Address    -> ");
    myGets(hotel->address, 64);
    printf("Phone      -> ");
    myGets(hotel->phone, 20);
    printf("Rooms      -> ");
    scanf("%d", &hotel->rooms);
    printf("Lux Rooms  -> ");
    scanf("%d", &hotel->lux_rooms);
    printf("Free Rooms -> ");
    scanf("%d", &hotel->free_rooms);
}

void printHotel(Hotel* hotel) {
    printf("Name       -> %s\n", hotel->name);
    printf("Stars      -> %d\n", hotel->stars);
    printf("Address    -> %s\n", hotel->address);
    printf("Phone      -> %s\n", hotel->phone);
    printf("Rooms      -> %d\n", hotel->rooms);
    printf("Lux Rooms  -> %d\n", hotel->lux_rooms);
    printf("Free Rooms -> %d\n", hotel->free_rooms);
}

void parseStrHotel(Hotel* hotel, char* s) {
    char* ptr;
    ptr = strtok(s, "|");
    strcpy(hotel->name, ptr);
    ptr = strtok(NULL, "|");
    hotel->stars = atoi(ptr);
    ptr = strtok(NULL, "|");
    strcpy(hotel->address, ptr);
    ptr = strtok(NULL, "|");
    strcpy(hotel->phone, ptr);
    ptr = strtok(NULL, "|");
    hotel->rooms = atoi(ptr);
    ptr = strtok(NULL, "|");
    hotel->lux_rooms = atoi(ptr);
    ptr = strtok(NULL, "|");
    hotel->free_rooms = atoi(ptr);
}

void getStrHotel(Hotel* hotel, char* s) {
    sprintf(s, "%s|%d|%s|%s|%d|%d|%d",
            hotel->name,
            hotel->stars,
            hotel->address,
            hotel->phone,
            hotel->rooms,
            hotel->lux_rooms,
            hotel->free_rooms
    );
}


typedef struct HotelList_ {
    Hotel* hotels;
    int nhotels;
    int alloc;
} HotelList;

void initHotelList(HotelList* list) {
    list->nhotels = 0;
    list->alloc = 0;
    list->hotels = NULL;
}

void freeHotelList(HotelList* list) {
    if (list->hotels != NULL) {
        free(list->hotels);
    }
    initHotelList(list);
}

void reallocHotelList(HotelList* list, int new_alloc) {
    int i;
    Hotel* old_hotels;

    old_hotels = list->hotels;
    list->hotels = (Hotel*)malloc(new_alloc * sizeof(Hotel));
    for (i = 0; i < list->nhotels; ++i) {
        list->hotels[i] = old_hotels[i];
    }
    list->alloc = new_alloc;
    if (old_hotels) {
        free(old_hotels);
    }
}

void addInHotelList(HotelList* list) {
    if (list->alloc == 0) {
        reallocHotelList(list, 1);
    } else if (list->nhotels == list->alloc) {
        reallocHotelList(list, list->alloc * 2);
    }
    inputHotel(list->hotels + list->nhotels);
    ++list->nhotels;
}

int isEmptyHotelList(HotelList* list) {
    return list->nhotels == 0;
}

int lenHotelList(HotelList* list) {
    return list->nhotels;
}

void printHotelList(HotelList* list) {
    int i, line_len;
    char line[256];
    int name_len = 4;
    int address_len = 7;
    int phone_len = 5;

    for (i = 0; i < list->nhotels; ++i) {
        name_len = max(name_len, strlen(list->hotels[i].name));
        address_len = max(address_len, strlen(list->hotels[i].address));
        phone_len = max(phone_len, strlen(list->hotels[i].phone));
    }
    line_len = 45 + name_len + address_len + phone_len;
    for (i = 0; i < line_len; ++i) {
        line[i] = '*';
    }
    line[line_len] = '\0';

    printf(" %s\n", line);
    printf("| %2s | %*s | %5s | %*s | %*s | %5s | %5s | %5s |\n",
           "#",
           name_len, "Name",
           "Stars",
           address_len, "Address",
           phone_len, "Phone",
           "Rooms",
           "Lux",
           "Free"
    );
    printf(" %s\n", line);
    for (i = 0; i < list->nhotels; ++i) {
        printf("| %2d | %*s | %5d | %*s | %*s | %5d | %5d | %5d |\n",
           i + 1,
           name_len, list->hotels[i].name,
           list->hotels[i].stars,
           address_len, list->hotels[i].address,
           phone_len, list->hotels[i].phone,
           list->hotels[i].rooms,
           list->hotels[i].lux_rooms,
           list->hotels[i].free_rooms
        );
    }
    printf(" %s\n", line);
}

void removeByIndexHotelList(HotelList* list, int index) {
    int i;
    for (i = index; i + 1 < list->nhotels; ++i) {
        list->hotels[i] = list->hotels[i + 1];
    }
    --list->nhotels;
}

void printBestFromHotelList(HotelList* list) {
    int free_rooms = -1, i, index = 0, stars = -1;
    for (i = 0; i < list->nhotels; ++i) {
        if (free_rooms < list->hotels[i].free_rooms) {
            index = i;
            free_rooms = list->hotels[i].free_rooms;
            stars = list->hotels[i].stars;
        } else if (free_rooms == list->hotels[i].free_rooms && stars < list->hotels[i].stars) {
            index = i;
            stars = list->hotels[i].stars;
        }
    }
    printHotel(&list->hotels[index]);
}

void readFromFileHotelList(HotelList* list, char* file) {
    FILE* fp;
    char buffer[256];

    if ((fp = fopen(file, "r")) == NULL) {
        return;
    }
    while (fgets(buffer, 256, fp) != NULL) {
        strip(buffer);
        if (strlen(buffer) == 0) {
            break;
        }
        if (list->alloc == 0) {
            reallocHotelList(list, 1);
        } else if (list->nhotels == list->alloc) {
            reallocHotelList(list, list->alloc * 2);
        }
        parseStrHotel(list->hotels + list->nhotels, buffer);
        ++list->nhotels;
    }
    fclose(fp);
}

void saveInFileHotelList(HotelList* list, char* file) {
    char buffer[256];
    int i;
    FILE* fp;

    fp = fopen(file, "w");
    for (i = 0; i < list->nhotels; ++i) {
        getStrHotel(list->hotels + i, buffer);
        fprintf(fp, "%s\n", buffer);
    }
    fclose(fp);
}


void printMenu() {
    printf("[1] Add hotel\n");
    printf("[2] Print hotels\n");
    printf("[3] Remove hotel by number\n");
    printf("[4] Best Hotel with most free rooms\n");
    printf("[0] Exit\n");
    printf(" -> ");
}

int main() {
    char filename[] = "store.txt";
    int command, number;
    HotelList hotels;
    initHotelList(&hotels);

    readFromFileHotelList(&hotels, filename);

    do {
        printMenu();
        scanf("%d", &command);
        if (command == 1) {
            printf("\nEnter information about Hotel:\n");
            addInHotelList(&hotels);
            printf("\n[OK] Hotel was added\n\n");
        } else if  (command == 2) {
            if (isEmptyHotelList(&hotels)) {
                printf("\n[OK] Hotel list is empty\n\n");
            } else {
                printf("\n[OK] Hotel list:\n");
                printHotelList(&hotels);
                printf("\n");
            }
        } else if (command == 3) {
            if (isEmptyHotelList(&hotels)) {
                printf("\n[OK] Hotel list is empty\n\n");
                continue;
            }
            printf("\nEnter number -> ");
            scanf("%d", &number);
            if (number < 1 || number > lenHotelList(&hotels)) {
                printf("\n[FAIL] No hotel with such number\n\n");
            } else {
                removeByIndexHotelList(&hotels, number - 1);
                printf("\n[OK] Hotel succesfully removed\n\n");
            }
        } else if (command == 4) {
            if (isEmptyHotelList(&hotels)) {
                printf("\n[OK] Hotel list is empty\n\n");
                continue;
            }
            printf("\n[OK] Best hotel with most free rooms:\n");
            printBestFromHotelList(&hotels);
            printf("\n");
        } else if (command == 0) {
            printf("\n[OK] Bye\n\n");
        } else {
            printf("\n[FAIL] Wrong command!\n\n");
        }
    } while (command != 0);

    saveInFileHotelList(&hotels, filename);
    freeHotelList(&hotels);
    return 0;
}
