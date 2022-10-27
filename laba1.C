 #include <stdio.h>

        int min(int sum_a, int sum_b)
        {
           if (sum_a<sum_b) return sum_a;
           else return sum_b;
        }
        int main()
        {
           int a=13, b=12, sum_a=0, sum_b=0, b1=b;
           while (a)
           {
             sum_a+=a%10;
             a/=10;
           }
           while(b)
           {
             sum_b+=b%10;
             b/=10;
           }
           printf("%f", (float) min(sum_a, sum_b)/b1);
           return 0;
        }
