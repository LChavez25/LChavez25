#include <stdio.h>
void main()
{
    //Variable declaration
    char name[20],food[20];
    int age,a,b;
    //Input name ,food and age
    printf("Enter your name:\n");
    scanf("%s",&name);
     printf("Enter your age:\n");
    scanf("%d",&age);
    printf("Enter your favourite food:\n");
    scanf("%s",&food);
    //Increment the age 
    a=age+2;
    //Print the value
    printf("My Name is: %s and My favourite food is %s!",name,food);
    printf("\n***\n");
    printf("I am %d  years old and in 2 years I will be %d!",age,a);
    getch();
}
