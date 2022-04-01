#include <stdio.h>
int get_input(char message[])
{
int x;
printf("%s",message);
printf("\n");
scanf("%d",&x);
return x;
}
int check_even(int n)
{
if(n%2==0){
return 1;
}
return 0;
}
int main()
{
int even,odd;
even=get_input("--Enter an even number.");
while(1)
{
if(check_even(even)==0){
even=get_input("That is not even. Enter an even number.");}
else{
break;
}
}
printf("\n");
odd=get_input("--Ok thanks! Now enter odd number.");
while(1){
if(check_even(odd)==1){
odd=get_input("That is not odd. Enter an odd number."); }
else{
break;
}
}
printf("\n**Thanks bye!**");

return 0;
}
