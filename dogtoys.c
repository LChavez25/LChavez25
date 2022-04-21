#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//to show all the toys Possible for the dog_favorite and printing the names and prices for the same
void show_all(char item_name[][20],int item_price[],int n,char dog_name[])
{
    int i;
    //printing the dog name
    printf("--Possible toys for %s!--\n",dog_name);
    //looping till number toys in the item_name i.e 3 always
    for(i=0;i<n;i++)
    {
        //printing the item_name
        printf("%s: ",item_name[i]);
        //printing the item_price
        printf("$%d\n",item_price[i]);
    }
}
//toy_receipt is to print the dog_favorite toy under budget and giving the receipt about them
void toy_receipt(char file_name[],char item_name[][20],char dog_favorite[][20])
{
    // creating file pointer to work with files
    FILE *fptr;
    // opening file in writing mode
    fptr = fopen(file_name, "w");
    char choice;
    //to store the receipts tempararly
    char receipt[3][20];
    //declaring the required varianles and receipt_index to store the receipts
    int receipt_index=0,i,j,k;
    printf("Going through toys...\n");
    //looping through all toys in item_name
    for(i=0;i<3;i++)
    {
        //looping through all dog_favorite items
        for(j=0;j<3;j++)
        {
            //if item_name matches with the dog_favorite toy, then do the below acknowledgement to user
            if(!(strcmp(item_name[i],dog_favorite[j])))
            {
                //printing the macthed item_name
                printf("--Found a matching favorite! %s!!\n",item_name[i]);
                //prompting the user for adding it to receipt or not i,e if he wish to buy it or not
                printf("Add to receipt? y or n\n");
                //reading the choice
                scanf("\n%c",&choice);
                //if the choice is yes
                if(choice=='y')
                {
                    //copy the item_name to receipt array , to hold the toys temporarly
                    strcpy(receipt[receipt_index++],item_name[i]);
                    //printing the Current receipt
                    printf("Current receipt:\n--Toys to buy!--\n");
                    //looping through all items in the receipt
                    for(k=0;k<receipt_index;k++)
                    {
                        //printing the receipt
                        printf("%d. %s\n",k+1,receipt[k]);
                    }
                    //writing item_name into the file
                    fprintf(fptr, "%s\n", item_name[i]);
                }
            }
        }
    }
    //closing the file pointer
    fclose(fptr);
}
// get_item is to get all the 3 items which are under budget
int get_item(char file_name[],char item_name[][20],int item_price[],int budget)
{
    //buffer to store the word from the file
    char buffer[100];
    //check is check , present line in the file is whether a toy name or price
    int check=0;
    //return_value stores the number of toys are available under budget
    int return_value=0;
    //temp_toy stores the toyname temporarly
    char temp_toy[100];
    //item_name_index is helps to store the toynames
    int item_name_index=0;
    //item_price_index helps to store the prices of the toys
    int item_price_index=0;
    //pointer to the file
    FILE *fptr;
    //opening the file input.txt in reading mode
    fptr = fopen(file_name, "r");
    //reading the file until EOF reached and storing each line in buffer
    while (fgets(buffer, sizeof buffer, fptr) != NULL)
    {
        //finding the length of the buffer
        int len=strlen(buffer);
        //if the exta new line presents in the word got from the file, then remove it by making the last character null
        if(buffer[len-1]=='\n')
        {
            //deleting the newline
            buffer[len-1]='\0';
            if(check%2==0)
            {
                //temporarly holdint the toy name in temp_toy
                strcpy(temp_toy,buffer);
            }
            else
            {
                //if the price is less than or equal to budget then store the toyname and price in item_name and item_price arrays
                if(atoi(buffer)<=budget)
                {
                    //incrementing the return_value since we found one toy under budget
                    return_value++;
                    //storing the toyname and price to respective arrays
                    strcpy(item_name[item_name_index++],temp_toy);
                    item_price[item_price_index++]=atoi(buffer);
                    //if the return_value is 3, i.e if we found the 3 items under budget before EOF reached, then break the loop i.e stop reading
                    if(return_value==3)
                        break;
                }
            }
        }
        //incrementing the check
        check++;
    }
    //closing the file pointer
    fclose(fptr);
    //return the return_value
    return return_value;
}
int main(int argc, char **argv)
{
    //declaring dog_favorite
    char dog_favorite[3][20];
    //copying all command line argument values to dog_favorite array
    strcpy(dog_favorite[0],argv[1]);
    strcpy(dog_favorite[1],argv[2]);
    strcpy(dog_favorite[2],argv[3]);
    //declaring item_name and item_price arrays
    char item_name[3][20];
    int item_price[3];
    //calling the get_item
    int n=get_item(argv[5],item_name,item_price,10);
    //if the number of items is 3, then call show_all and toy_receipt functions
    if(n==3)
    {
        //calling the show_all
        show_all(item_name,item_price,3,argv[4]);
        //calling toy_receipt
        toy_receipt("dogtoyreceipt.txt",item_name,dog_favorite);
    }
    else
    {
        printf("Sorry...%d is not enough toys for %s to choose from! :(\n",n,argv[4]);
    }
    return 0;
}

