#include <stdio.h>
#include <string.h>  

int main()
{
    // creating array of days name
    char days_of_week[5][20] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    // initializing variables
    char day1[20], day2[20];
    int daily_pollutants[5][3];
    int d1, d2;

    // Taking input from used for each day
    for(int i = 0; i < 5; i++){
        printf("~%s\n",days_of_week[i]);
        printf("Mold spores-");
        scanf("%d",&daily_pollutants[i][0]);
        printf("Pollen particles-");
        scanf("%d",&daily_pollutants[i][1]);
        printf("Dust particles-");
        scanf("%d",&daily_pollutants[i][2]);
        printf("\n");
    }
    
    // do-while loop for repetitive calling
    printf("-------------------------\n");
    do{
        // taking day 1 from user
        printf("Enter day 1: ");
        scanf("%s", day1);
        // condition if day 1 is equal to "exit" then exit from program
        if(strcmp(day1, "exit")==0){
            printf("Exiting...");
            return 0;
        }
        printf("Enter day 2: ");
        scanf("%s", day2);
        
        // converting day name in integer for indexing
        for(int i = 0; i < 5; i++){
            if(strcmp(day1,days_of_week[i])==0){
                d1 = i;
            }
            else if(strcmp(day2,days_of_week[i])==0){
                d2 = i;
            }
        }
        
        // codition for mold spores
        if(daily_pollutants[d1][0] > daily_pollutants[d2][0]){
            printf(" -%s has more mold spores.\n", days_of_week[d1]);
        }
        else if(daily_pollutants[d1][0] < daily_pollutants[d2][0]){
            printf(" -%s has more mold spores.\n", days_of_week[d2]);
        }
        else{
            printf(" -Both days have the same number of mold spores.\n");
        }
        
        // codition for pollen particles
        if(daily_pollutants[d1][1] > daily_pollutants[d2][1]){
            printf(" -%s has more pollen particles.\n", days_of_week[d1]);
        }
        else if(daily_pollutants[d1][1] < daily_pollutants[d2][1]){
            printf(" -%s has more pollen particles.\n", days_of_week[d2]);
        }
        else{
            printf(" -Both days have the same number of pollen particles.\n");
        }
        
        // condition for dust particles
        if(daily_pollutants[d1][2] > daily_pollutants[d2][2]){
            printf(" -%s has more dust particles.\n", days_of_week[d1]);
        }
        else if(daily_pollutants[d1][2] < daily_pollutants[d2][2]){
            printf(" -%s has more dust particles.\n", days_of_week[d2]);
        }
        else{
            printf(" -Both days have the same number of dust particles.\n");
        }
    }while(1);
    
    
    return 0;
}
