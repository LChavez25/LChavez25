#include<stdio.h>
#include<string.h>

int leapyear(int year){
   if(year%400==0)return 1;
   else if(year%100==0) return 0;
   else if(year%4==0)return 1;
   else return 0;
}

int three_nums(int a, int b, int c){
  
   if(c>b && c>a && b>a)return 1;
   else return 0;
}

void print_out(int size, char c, char* word){
  
   if(strlen(word)>size || size%2==1)printf("Cant print this :(");
   else{
       int half = size/2;
       int top;int col;
       for(top=1; top<=size; top++)printf("%c",c);printf("\n");
       for(top=1;top<=half/2;top++){
           for(col=1;col<=size;col++){
               if(col==1 || col==size)printf("%c",c); else printf(" ");
           }printf("\n");
       }
      
       int spaces = (size-strlen(word))/2;
       for(top=1;top<=spaces;top++)if(top==1)printf("%c",c);else printf(" ");
       printf("%s",word);
       for(top=1;top<=size-strlen(word)-spaces;top++)
       if(top==(size-strlen(word)-spaces))printf("%c",c);else printf(" ");
       printf("\n");
      
      
       for(top=1;top<=half/2;top++){
           for(col=1;col<=size;col++){
               if(col==1 || col==size)printf("%c",c); else printf(" ");
           }printf("\n");
       }
  
       for(top=1; top<=size; top++)printf("%c",c);printf("\n");
       printf("\n");
      
   }
   printf("\n");
  
}

int main(){
  
   printf("Is 1900 leap year? %d\n", leapyear(1900));
   printf("Is 2020 leap year? %d\n", leapyear(2020));
   printf("2 3 4 ascending? %d\n",three_nums(2,3,4));
   printf("2 3 1 ascending? %d\n",three_nums(2,3,1));
   print_out(10,'*',"Hello");
   //print_out(10,'*',"HelloGoodMorning");
   print_out(30,'*',"Good Morning");
}
