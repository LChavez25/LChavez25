#include<stdio.h>
#include<string.h>
int main()
{
    char p1[20],p2[20],p3[20],test[20]; //declaring char array for strong name
    int pill_1=0,pill_2=0,pill_3=0,tpill=0,val; //these variable will store pills
    printf("Enter Patient 1 name: "); //taking name from user
    scanf("%s",&p1);
    printf("Enter Patient 2 name: ");
    scanf("%s",&p2);
    printf("Enter Patient 3 name: ");
    scanf("%s",&p3);
    while(1)
    {
        printf("Enter Patient name taking pill: ");
        scanf("%s",&test);
        if(strcmp(test,p1)==0) //checking whether entered name already exist or not using strcmp function which compare 2 string and give 0 if bot are same.
        {
            printf("Patient found-patient #1: How many pill>?");
            scanf("%d",&val);      //taking input pill from user for specific patient
            pill_1=pill_1+val;
            printf("Total pill so far for %s: %d\n",test,pill_1);
            tpill=tpill+pill_1; //storing total pills
        }
        else if(strcmp(test,p2)==0)
        {
            printf("Patient found-patient #2: How many pill>?");
            scanf("%d",&val);
            pill_2=pill_2+val;
            printf("Total pill so far for %s: %d\n",test,pill_2);
            tpill=tpill+pill_2;
        }
       else if(strcmp(test,p3)==0)
        {
            printf("Patient found-patient #3: How many pill>?");
            scanf("%d",&val);
            pill_3=pill_3+val;
            printf("Total pill so far for %s: %d\n",test,pill_3);
            tpill=tpill+pill_3;
        }
        else if(strcmp(test,"exit")==0)
        {
              printf("Exiting...\n"); //ending program if user enter exit
              break;
        }
        else
        {
            printf("Sorry patient not found\n"); //if user enter any other name,it will prompt user to enter again
            continue;
        }

    }
    char check[10];
    while(1)
    {
    printf("Would you like to see the total bill amount for each patient ?\n");
    scanf("%s",check);
    if(strcmp(check,"yes")==0)   //this will print total pill for each patient if user enter yes
    {
        printf("%s:%d \n",p1,pill_1);
        printf("%s:%d \n",p2,pill_2);
        printf("%s:%d \n",p3,pill_3);
        break;
    }
    else if(strcmp(check,"no")==0)
    {
        printf("Ok. Total pills dispensed: %d\n",tpill); //this will print combined total pill for all user
        break;
    }
    else
    {
        printf("Answer not recognized. Answer yes or no.\n");
        continue;
    }
    }
}
