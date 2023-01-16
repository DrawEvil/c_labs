void getch_tilda()
{
 int c;
 do
 {
 c = mygetch();
 }
 while (c != '~');
}

int process_key()
{
 int start_char = mygetch();
 switch (start_char)
 {
 case '[':
 {
 int first_char = mygetch();
 if (first_char == '1')
 {
 int second_char = mygetch();
 if (second_char == '9') // Esc[19~
 return 1;
 else if (isdigit(second_char))
 getch_tilda();
 }
 else if (isdigit(first_char))
 getch_tilda();
 }
 break;

 case 'O':
 {
 char c = mygetch();
 if (isdigit(c))
 mygetch();
 }
 break;
 }
 
 return 0;
}

int main()
{
 while (1)
 {
 char c;
 c = mygetch();
 if (iscntrl(c))
 {
 if (c == 27)
 {
 int result = process_key();
 if (result == 1)
 exit(EXIT_SUCCESS);
 }
 }
 else
 {
 if (islower(c))
 c = toupper(c);
 printf("%c", c);
 }
 }
 printf("\n");
 return 0;
}
