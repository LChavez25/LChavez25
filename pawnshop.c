#include <stdio.h>
#include <string.h>

//Utility to compare strings
int compareStrings(char *str1, char *str2){
    if(strlen(str1) != strlen(str2)){
        return 0;
    } 
    int stringLen = strlen(str1);
    while(stringLen){
        if(*str1 != *str2){
            return 0;
        }
        str1++; str2++;
        stringLen--;
    }    
    return 1;
}

//Helper function for get_available_items
void get_available_items_helper(FILE *fp, char *buff, char *searchType){
    char searchElement[50];
    int count = 0;
    int lineNo = 0;
    printf("I see that -%s- is important in this shipment. Any specific %s to count: ", searchType, searchType);
    scanf("%s", searchElement);
    printf("Ok. I will keep the count of the number of the following that I find: %s\n", searchElement);
    while(!feof(fp)){
        if(lineNo%3==0){
            fscanf(fp, "%s", buff);
            printf("--%s\n", buff );
            if(compareStrings(buff, searchElement)){
                count++;
            }
        }
        lineNo++;
        fscanf(fp, "%s", buff);
    }
    printf("%d\n", count);
}

void get_available_items(char *fileName, char *searchType){
    FILE *fp;
    char buff[255];
    fp = fopen(fileName, "r");
    if(searchType=="type"){
        
    } else if(searchType=="stone") {
        fscanf(fp, "%s", buff); //To skip 1 line
    } else if(searchType=="authentic"){
        fscanf(fp, "%s", buff); //To skip 2 lines
        fscanf(fp, "%s", buff);
    } else {
        printf("Unknown parameter to check...-1\tyou have to pass one of the following: type, stone, authentic");
        return;
    }
    get_available_items_helper(fp, buff, searchType);
}

int main()
{
    get_available_items("jewelry.txt", "stone"); //Enter file name and search type.
}
