#include <stdio.h>
#include <string.h>

int valid_num(char wallet[20])
{
    return (strlen(wallet) == 16) && (wallet[0] == '5' || wallet[0] == '4');
}

void get_creditcard_info(char (*wallet)[20], int *cvv, int n)
{
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("--%d. Enter credit card number: ", i + 1);
            scanf("%s", wallet + i);
            if (valid_num(wallet[i]))//checks the validity of the card number
                break;
            else
                printf("\nNot a valid number. ");
        } while (1);
        printf("\nEnter the CVV number: ");
        scanf("%d", cvv + i);
    }
    printf("\n--All credit cards in your wallet:");//prints all the cards
    for (int i = 0; i < n; i++)
    {
        printf("\n%d. %s", i + 1, wallet + i);
    }
}

int use_creditcard(char (*wallet)[20], int *cvv, int n)
{
    char card[20];
    int cv;
    printf("\nEnter card to use: ");
    scanf("%s", card);
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(wallet[i], card))//compares the card
        {
            printf("Enter CVV number: ");
            scanf("%d", &cv);
            if (cv == cvv[i])//compares the cvv
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    char wallet[3][20];
    int cvv_numbers[3];

    get_creditcard_info(wallet, cvv_numbers, 3);
    int answer = use_creditcard(wallet, cvv_numbers, 3);

    if (answer)
    {
        printf("Card accepted!\n");
    }
    else
    {
        printf("Card rejected.\n");
    }
    return 0;
}
