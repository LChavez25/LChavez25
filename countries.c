#include<stdio.h>
#include<string.h>

// function make_lower_case() takes 2 arguments - a string and its length. it converts all the alphabets to lower case
void make_lower_case(char *string, int length)
{
   // iterate for loop from i=0 to length of the string
   for(int i=0;i<length;i++)
   {
       // if the ith character in the given string is in upper case
       if(string[i]>=65 && string[i]<=90)
           // convert it into lower case by adding 32 to it
           string[i] = string[i]+32;
   }
}

// function enter_country_info() takes 3 arguments, 2d characer array countries, 2d character aray capitals, and a number which specifies no.of countrie's info the user want
void enter_country_info(char countries[][20], char capitals[][20], int size)
{
   // iterate for loop size times
   for(int i=0;i<size;i++)
   {
       // ask user to enter country
       printf("--Enter country: ");
      
       // read country name from user
       gets(countries[i]);
      
       // call function make_lower_case() by passing ith country in coutries array, and length of ith country
       make_lower_case(countries[i], strlen(countries[i]));
      
       // print ith country
       printf(" Saved: %s\n", countries[i]);
      
       // ask user to enter capital of ith country
       printf(" Enter capital of %s: ", countries[i]);
      
       // read capital of ith country from user
       gets(capitals[i]);
      
       // call function make_lower_case() by passing capital of ith country in capitals array, and length of ith capital
       make_lower_case(capitals[i], strlen(capitals[i]));
      
       // print capital of ith country
       printf(" Saved: %s\n\n", capitals[i]);
      
      
      
   }
}

// function get_input() takes 2 arguments, a character arry to print, and a character array to store answer read from user
void get_input(char *header,char *answer)
{
   // print header message
   printf("%s ", header);
  
   // read answer from user
   gets(answer);
}

// function find_answer() takes 2 arguments list of strings, and no.of strings, and answer
int find_answer(char strings[][20], int size, char *answer)
{
   // iterate for loop from i=0 to size
   for(int i=0;i<size;i++)
   {
       // compare each ith string with answer, if both are equal
       if(strcmp(strings[i],answer)==0)
           // then return value of i
           return i;
   }
   // if none of the strings are matched with string answer, then return -1
   return -1;
}

// main() function. given in the question
int main(int argc, char **argv)
{
   char countries[4][20];
   char capitals[4][20];
   char answer[20];
  
   enter_country_info(countries, capitals, 4); /*15 points */
   get_input("Enter a capital or country:", answer); /*4 points */
   make_lower_case(answer, strlen(answer));
  
   int n = find_answer(countries, 4, answer); /*15 points */
  
   if(n==-1)
   {
       n=find_answer(capitals, 4, answer);
       if(n==-1)
       {
           printf("nothing found for that input.\n");
       }
       else
       {
           printf("That is the capital of: %s\n\n", countries[n]);
       }
   }
   else
   {
       printf("The capital of that country is: %s\n\n", capitals[n]);
   }
}
