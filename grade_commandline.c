#include <stdio.h>
float calculate_grades(int num_grades, char type[]);
void output_letter(float grades[3][2]);
int main(void)
{
    float nHW,wHW,nEx,wEx,nQz,wQz,weights;
    float HwAvg, ExAvg, QzAvg;
    
    scanf("%f %f %f %f %f %f", &nHW, &wHW, &nEx, &wEx, &nQz, &wQz);
    weights = wHW + wEx + wQz;
    if (weights > 100)
    {
        printf("Missing info ... Exiting...");
        return 0;
    }
    char *type = "HW";
    HwAvg = calculate_grades(nHW, type);
    type = "exam";
    ExAvg = calculate_grades(nEx, type);
    type = "quiz";
    QzAvg = calculate_grades(nQz, type);
    printf("%.2f %.2f %.2f\n", HwAvg, ExAvg, QzAvg);
    wHW = wHW/100;
    wEx = wEx/100;
    wQz = wQz/100;
    float grades[3][2] = {{wHW, HwAvg},{wEx, ExAvg}, {wQz, QzAvg}};
    output_letter(grades);
    return 0;
}

float calculate_grades(int num_grades, char type[])
{
    int i, grade;
    float avg, sum = 0.00;
    for(i=1; i <= num_grades; i++){
        printf("Enter %s grade %d:",type, i);
        scanf("%d", &grade);
        if (grade >= 0 && grade <= 100) 
            sum += grade;
        else{
            while(1)
            {
                printf("-- Not a valid grade. Re-enter: ");
                scanf("%d", &grade);
                if (grade >= 0 && grade <= 100)
                    break;
            }
            sum += grade;
        }
    }
    avg = sum/num_grades;
    return avg;
}

void output_letter(float grades[][2])
{
    float WtHwAvg, WtExAvg, WtQzAvg, FinalAvg;
    WtHwAvg = grades[0][0] * grades[0][1];
    WtExAvg = grades[1][0] * grades[1][1];
    WtQzAvg = grades[2][0] * grades[2][1];
    FinalAvg = WtHwAvg+WtExAvg+WtQzAvg;
    printf("Final numeric grade: %.2f\n", FinalAvg);
    if(FinalAvg <= 100 && FinalAvg > 90)
        printf("You have a A!");
    else if(FinalAvg <= 90 && FinalAvg > 80)
        printf("You have a B!");
    else if(FinalAvg <= 80 && FinalAvg > 70)
        printf("You have a C!");
    else if(FinalAvg <= 100 && FinalAvg > 60)
        printf("You have a D!");
    else if(FinalAvg <= 100 && FinalAvg > 50)
        printf("You have a E!");
    else if(FinalAvg <= 100 && FinalAvg > 40)
        printf("You have a F!");
    else
        printf("Fail!!");
}
