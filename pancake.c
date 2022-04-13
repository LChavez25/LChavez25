#include<stdio.h>
#include<string.h>

//enter_favorites() function checks if item is available
int enter_favorites(char enter_favorites[][20],int size){
    //Creating a char array to store a string
    char str[100];
    //creating integer variable to keep count of invalid inputs
    int count=0;
    //Iterating through for loop 'size' times
    for (int i = 0; i < size; i++)
    {
        printf("Enter favorite pancake: ");
        gets(str); 
        //If user input is pumpkin or strawberry then we iterate through 
        //while loop till user enter other flavour
        //Using strcmp() function to compare two strings.
        //If strcmp(str1,str2)==0 then str1,str2 are equal
        while(strcmp(str,"pumpkin")==0 || strcmp(str,"strawberry")==0){
            printf("--Yuck! Pick something else: ");
            gets(str);
            //Incrementing count for invalid invalid
            count++;
        }  
    }
    return count;
}
//calculate_price() function calculates the total cost of entered pancakes.
float calculate_price(char fav_pancskes[][20],int size){
    float sum=0.0;
    //Creating a char array to store a string
    char str[25];
    int count=0;
    //Iterating through for loop 'size' times
    for (int i = 0; i < size; i++)
    {
        printf("Enter favorite pancake: ");
        gets(str); 
        //If user input is pumpkin or strawberry then we iterate through 
        //while loop till user enter other flavour
        //Using strcmp() function to compare two strings.
       
        while(strcmp(str,"pumpkin")==0 || strcmp(str,"strawberry")==0){
            printf("--Yuck! Pick something else: ");
            gets(str);
            count++;
        }  

         //If strcmp(str1,str2)==0 then str1,str2 are equal
        if(strcmp(str,"chocolate chip")==0 || strcmp(str,"blueberry")==0 || strcmp(str,"Chocolate chip")==0 || strcmp(str,"Blueberry")==0)
        sum=sum+5;
        else if(strcmp(str,"vanilla")==0 || strcmp(str,"Vanilla")==0)
        sum=sum+3;
        else{
            sum=sum+1;
        }
        
        if (count>3)
        {
            sum=sum*2;
        }
        
    }
    return sum;
}

int main(void){

    char fav_pancake[][20]={};
    //Calling enter_favorites() function to check if item is available
    printf("%d\n\n",enter_favorites(fav_pancake,4));
    //calculate_price() function calculates the total cost of entered pancakes.
    printf("%.2f",calculate_price(fav_pancake,4));
}
