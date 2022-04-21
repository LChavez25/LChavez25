#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_reactions(char *file, int group[3][3])
{
FILE *fp = fopen(file, "r");
char buf[100]={'\0'};
int buf_len = 100;
int len = 0;
int i = 0;
int j = 0;

char *newBuff;
printf("Getting focus group info...\n");
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{
fgets(buf, buf_len, fp);

len = strlen(buf);
newBuff = (char *)malloc(len*(sizeof(char)));
strncpy(newBuff, buf, len);
newBuff[len]='\0';

if(j==0)
{
printf("Participant %d: %s\n", i+1, newBuff);
}
else
{
if(strstr(newBuff, "Yes")!=NULL)
{
group[i][j-1]=1;
}
else if(strstr(newBuff, "No")!=NULL)
{
group[i][j-1]=0;
}
}
free(newBuff);
}
}
fclose(fp);
return len;
}
float get_participant_likes(int group[3][3], char *pie)
{ int i = 0;
int j = 0;
float sum = 0;
if(strcmp(pie, "Pumpkin")==0)
{
printf("Calculating total likes for flavor: %s\n", pie);
j=0;
for(i=0;i<3;i++)
{
sum = sum + group[i][j];
}
}
else if(strcmp(pie, "Keylime")==0)
{
printf("Calculating total likes for flavor: %s\n", pie);
j=1;
for(i=0;i<3;i++)
{
sum = sum + group[i][j];
}
}
else if(strcmp(pie, "Pecan")==0)
{
printf("Calculating total likes for flavor: %s\n", pie);
j=2;
for(i=0;i<3;i++)
{
sum = sum + group[i][j];
}
}
sum = (sum/3);
return sum;
}
void show_data(int group[3][3], float percent[3])
{
int i = 0;
int j = 0;
char yn[4] = {'\0'};
FILE *ptr;
ptr = fopen("reactionsOutput.txt", "w");
for(i=0;i<3;i++)
{
printf("--participant %d:\n", i+1);
fprintf(ptr, "--participant %d:\n", i+1);
for(j=0;j<3;j++)
{
if(group[i][j]==1)
{
strcpy(yn, "Yes");
}
else if(group[i][j]==0)
{
strcpy(yn, "No");
}
if(j==0)
{
printf("Pumpkin: (Total likes-%.2f)%s\n", percent[j], yn);
fprintf(ptr, "Pumpkin: (Total likes-%.2f)%s\n", percent[j], yn);
}
if(j==1)
{
printf("Keylime: (Total likes-%.2f)%s\n", percent[j], yn);
fprintf(ptr, "Keylime: (Total likes-%.2f)%s\n", percent[j], yn);
}
if(j==2)
{
printf("Pecan: (Total likes-%.2f)%s\n", percent[j], yn);
fprintf(ptr, "Pecan: (Total likes-%.2f)%s\n", percent[j], yn);
}
}
printf("\n");
fprintf(ptr,"\n");
}
fclose(ptr);
}
int main(int argc, char **argv)
{
int focus_group[3][3];
float percentage_likes[3];
int n=get_reactions("reactions.txt", focus_group);
if(n)
{
percentage_likes[0]=get_participant_likes(focus_group, "Pumpkin");
percentage_likes[1]=get_participant_likes(focus_group, "Keylime");
percentage_likes[2]=get_participant_likes(focus_group, "Pecan");

show_data(focus_group, percentage_likes);
}
return 0;
}
