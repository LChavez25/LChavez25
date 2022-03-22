#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
// intitalze of the months
char months[12][20] = {"january", "februrary", "march", "april",
"may", "june", "july", "august", "september",
"october", "november", "december"};
char input[20], output[20];
  
printf("Please enter the name of a month: ");
scanf("%s", input);
  
int flag = 0, index = 0;
int length = sizeof(months[0])/sizeof(months[0][0]);
for(int i = 0; i < length; i++)
{
output[i] = tolower(input[i]);
}
for(int i = 0; i < length; i++)
{
if(strcmp(months[i], output) == 0) // companre with the each month
{
flag = 1;
index = i;
}
}
output[0] = toupper(output[0]);
if(flag == 1) // if found
{
switch(index + 1)
{
case 1: printf("%s is the first month.", output); break;
case 2: printf("%s is the second month.", output); break;
case 3: printf("%s is the third month.", output); break;
case 4: printf("%s is the fourth month.", output); break;
case 5: printf("%s is the fifth month.", output); break;
case 6: printf("%s is the sixth month.", output); break;
case 7: printf("%s is the seventh month.", output); break;
case 8: printf("%s is the eighth month.", output); break;
case 9: printf("%s is the ninth month.", output); break;
case 10: printf("%s is the tenth month.", output); break;
case 11: printf("%s is the eleventh month.", output); break;
case 12: printf("%s is the twelveth month.", output); break;
}
}
  
else{ // if not found
printf("Unknown month: %s", input);
}
  
return 0;
}
