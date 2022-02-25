#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
int main() {
   int num,num2;
   char word[500];
   int stringlength;
   printf("\nEnter a Number between 4 and 6 Including it: ");
   scanf("%d", &num);
   if(!((num >= 4) && (num <= 6)))
   {
       printf("Number out of Range!\n");
       exit(1);
   }
   printf("\nEnter the text\n");
   scanf("%s",word);
   stringlength=strlen(word);
    if(stringlength >= 10)
   {
       printf("Too Many Letters!\n");
   }
   else    if(stringlength < num)
       printf("Too few Letters!\n");
   printf("\nEnter the a number\n");
   scanf("%d", &num2);
   int i =0;
       printf("\nThe Letters of word from beginning\n");
   while(word[i]!='\0')
   {
   printf("%c",word[i]);
   i++;
   if(i>=num2)
   exit(1);
     
   }
  
   return 0;
}

