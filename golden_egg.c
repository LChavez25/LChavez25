#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining SIZE
#define SIZE 4

//function to input information of names and eggs
void give_chicken_info(int eggs[SIZE],char names[SIZE][20])
{
    //loop to take info
    for(int i=0;i<SIZE;i++)
    {
        printf("Enter chicken name: ");
        scanf("%s",&names[i]);    //enter name

         if(i>=1)   //if there are already other chickens in array
        {
            int j=i-1;   //assign j the position one less

            while(j>=0 ) // until array reaches first element
            {
                if(strcmp(names[i],names[j])==0) //if the name entered is present already
                {
                    printf("We already have a chicken named %s . Give another name: ");
                    scanf("%s",&names[i]);   //input name again
                    j=i-1;  //assign position one less the the current chicken
                    continue;  //continue to check again if the name is unique
                }
                j--; //decrement iterator
            }

        }
        printf("How many eggs did %s lay? ",names[i]);
        scanf("%d",&eggs[i]);   //input egg numbers
    }
}

//function to calculate total eggs
int go_to_market(int eggs[SIZE])
{
    int sum=0;
    for(int i=0;i<SIZE;i++)
        sum+=eggs[i]; //calculate sum

    if(sum>=30)  //if farmer can sell
        return 0;
    else return 1;  //if farmer cant sell
}

//main method as in the question , not changed
int main(int argc, char **argv)
{

    int chicken_eggs[SIZE]={0};
    char chicken_names[SIZE][20];
    int value=1;
    while(value)
    {
        printf("~~~Welcome to the best chicken farm ever!!!~~~\n");
        give_chicken_info(chicken_eggs,chicken_names);
        value=go_to_market(chicken_eggs);

        if(!value)
        {
            printf("Congrats Farmer Bob! You get to go sell your golden eggs at the market! Good bye and good luck! :)\n\n");

        }

        else
        {
            printf("Sorry Farmer Bob.Let's try again to get enough golden eggs next month...\n\n");
        }
    }
}
