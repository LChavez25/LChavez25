#include<stdio.h>
#include<string.h>
int main(void)
{
   char str[20], ch;
   int total = 0, amount;
   while(1)
   {
       printf("\n\n***Welcome! Are you looking to donate or do you work here?\n");
       scanf("%[^\n]%*c", str);
       if (strcmp(str, "donate") == 0)
       {
           if (total >= 100)
           {
               printf("We already met our target but thanks!");
               continue;
           }
           else
           {
               printf("Great! How much? $");
               scanf("%d", &amount);
               total = total + amount;
           }
       }
       else if (strcmp(str, "work here") == 0)
       {
           printf("Total donated so far: $%d", total);
           continue;
       }
       else if (strcmp(str, "exit") == 0)
       {
           printf("Bye!\n");
           break;
       }
       scanf("%c", &ch);
   }
}
