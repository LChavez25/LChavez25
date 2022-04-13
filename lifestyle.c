#include<stdio.h>

#include<string.h>




float print_out_monthly(char monthly_expenses[][20], float expenses_money[],

float monthly_payments_income[][2])

{

float my_share, roomate_share;

for(int i=0;i<5;i++)

{

printf("\n\n%s: $%.2f",monthly_expenses[i], expenses_money[i]);

my_share =expenses_money[i]*monthly_payments_income[0][0];

roomate_share=expenses_money[i]*monthly_payments_income[0][1];

printf("\n--- Your Pay: $%.2f. Roommate Pay: $%.2f",my_share,roomate_share);

monthly_payments_income[1][0]-=my_share;

monthly_payments_income[1][1]-=roomate_share;

}

printf("\n\nAfter deductions\nYou have $%.2f left. Roommate has $%.2f left",

monthly_payments_income[1][0],monthly_payments_income[1][1]);

float balance=monthly_payments_income[1][0]+monthly_payments_income[1][1];

printf("\n\nYou have a total of %.2f after paying all bills",balance);

return balance;

}

//function to peform life change

//input: float monthly_expenses[][20]

// float expenses_money[],

// float monthly_payments_income[][2]

//Output: changes income or expense share

//side effects: Update monthly_payments_income[][2]

//

int life_change(char monthly_expenses[][20], float expenses_money[],

float monthly_payments_income[][2])

{

int c;

float amt;

char update[10], sure[5];

float myshare, roommateshare;

printf("\n\nWhat life change are you making?");

printf("\n1. Change the split");

printf("\n2. Change income");

printf("\nEnter Your Choice: ");

scanf("%d", &c);

if(c==1)

{

do

{

printf("\n\nWhat is the new split?");

printf("\nYou (in percentage): ");

scanf("%f", &myshare);

printf("Roommate (in percentage): ");

scanf("%f", &roommateshare);

if(roommateshare+myshare!=100)

printf("\nThis is not a valid Split! Split not changed!");

else

{

monthly_payments_income[0][0]=myshare/100;

monthly_payments_income[0][0]=roommateshare/100;

}

}

while((roommateshare+myshare)!=100);

return 1;

}

if(c==2)

{

do

{ printf("\n\nWho is updating income?");

scanf("%s",update);

if(update[0]=='m'||update[0]=='M'||update[0]=='r'||update[0]=='R')

break;

if(!((strcmp(update,"me")== 1) || (strcmp(update,"roommate")== 1)))

printf("\nNot a valid choice...");

}

while(!((strcmp(update,"me")==1) || (strcmp(update,"roommate")==1)));

printf("\nNew Amount? ");

scanf("%f", &amt);

float totalcost=0;

for(int i=0;i<5;i++)

totalcost+=expenses_money[i];

if(strcmp(update,"me")==1 && amt<(totalcost*monthly_payments_income[0][0]))

{

printf("Are you sure sure about this update? ");

scanf(" %s",sure);

if(strcmp(sure,"yes")==1)

return(-1);

}

if(strcmp(update,"roommate")==1 && amt<(totalcost*monthly_payments_income[0][1]))

{

printf("Are you sure sure about this update? ");

scanf(" %s",sure);

if(strcmp(sure,"yes")==1)

return(-1);

}

if(strcmp(update,"me")==1)

monthly_payments_income[1][0]=amt;

else

monthly_payments_income[1][0]=amt;

printf("\n\nMove on to next month...");

}

}

// function to return month name from

//month number

char* cmonth(int month_number)

{

switch(month_number)

{

case 1: return "January";

case 2: return "February";

case 3: return "March";

case 4: return "April";

case 5: return "May";

case 6: return "June";

case 7: return "July";

case 8: return "August";

case 9: return "September";

case 10: return "October";

case 11: return "November";

case 12: return "December";

}

}

//main function

int main()

{

char monthly_expenses[5][20]=

{ "Car Payment",

"Electricity",

"Rent",

"Groceries",

"Going Out"

};

float expenses_money[5];

float monthly_payments_income[2][2];

float savings = 0;

char month[20];

int year;

int month_number=1;

char choice[5];

int ch;

char buy[20];

float cost;

expenses_money[0]=450.50;

expenses_money[1]=90.50;

expenses_money[2]=1800.00;

expenses_money[3]=500.50;

expenses_money[4]=450.50;

monthly_payments_income[0][0]=0.6;

monthly_payments_income[0][1]=0.4;

monthly_payments_income[1][0]=4500.50;

monthly_payments_income[1][1]=3000.25;

printf("\nWhat Year It Is? ");

scanf("%d", &year);

int skip=0;

do

{

if(skip!=1)

{ monthly_payments_income[1][0]=4500.50;

monthly_payments_income[1][1]=3000.25;

printf("\n*** %s %d", cmonth(month_number), year);

float balance = print_out_monthly(monthly_expenses,expenses_money,monthly_payments_income);

if(balance>0)

{

printf("\nWould you like to put this in savings? ");

scanf(" %s", choice);

if(strcmp(choice,"yes")!=1)

{

printf("\nAdding to %.2f SAVINGS...", balance);

savings+=balance;

monthly_payments_income[1][1]=0;

printf("\nTotal savings is %.2f\n", savings);

}

}

}

printf("\n\nWould you like to:");

printf("\n1. Continue (to next month)");

printf("\n2. Make a life change");

printf("\n3. Buy Something Using Savings");

printf("\n4. Exit");

printf("\n\nEnter your choice (1 to 4): ");

scanf(" %d", &ch);

if(ch==2)

{

int val = life_change(monthly_expenses,expenses_money,monthly_payments_income);

if(val==-1)

printf("Life NOT changed");

}

if(ch==3)

{

printf("\n\n What are you buying? ");

scanf(" %s", buy);

printf("\nEnter the cost of %s: ", buy);

scanf("%f",&cost);

if(cost<=savings)

{

printf("\n\nYour Balance is enough to buy a %s", buy);

savings-=cost;

printf("\n\nBalance in Your Savings is %.2f", savings);

}

else

printf("\n\nSorry! Your Balance is not enough to buy a %s", buy);

skip=1;

continue;

}

month_number++;

skip=0;

if(month_number==13)

{

year++;

month_number=1;

}

if(ch==4)

return 0;

}

while(ch!=4);

return 0;

}
