#soruce code:word_start.c
#include <stdio.h>
#include <string.h>
int main(){
char a[100];
printf("Please enter a word:");
scanf("%s",a);
if(strlen(a)==0){
printf(" starts with neither a vowel nor a consonant");
}else{
if(a[0]>='a' && a[0]<='z'){
if(a[0]=='a' || a[0]=='e' || a[0]=='i' || a[0]=='o' || a[0]=='u'){
printf("%s starts with vowel.\n",a);
}else{
printf("%s starts with consonant.\n",a);
}
}else if(a[0]>='A' && a[0]<='Z'){
if(a[0]=='A' || a[0]=='E' || a[0]=='I' || a[0]=='O' || a[0]=='U'){
printf("%s starts with vowel.\n",a);
}else{
printf("%s starts with consonant.\n",a);
}
}else{
printf("%s starts with neither a vowel nor a consonant.\n",a);
}
}
return 0;
}





