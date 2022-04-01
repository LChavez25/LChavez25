#include <stdio.h>
#include <string.h>

int get_political_party(const char parties[2][20], int voter)
{
    char party[20];
    printf("Voter %d which political party? ");
    while (1)
    {
        scanf("%s", party);
        if (strcmp(parties[0], party) == 0)
            return 0;
        else if (strcmp(parties[1], party) == 0)
            return 1;
        else
            printf("Not valid. Enter again: ");
    }
}

int main()
{
    char political_party[2][20]; // Holds political parties
    int voters[4];

    printf("Enter party1: ");
    scanf("%s", &political_party[0]);
    printf("Enter party2: ");
    scanf("%s", &political_party[1]);

    printf("--Enter info for 4 voters:\n");
    for (size_t i = 0; i < 4; i++)
        voters[i] = get_political_party(political_party, i + 1);

    // Display voters parties
    for (size_t i = 0; i < 4; i++)
        printf("%d ", voters[i]);

    printf("\n");

    char response[4];
    int voter;
    while (1)
    {
        printf("\nEnter voter[1-4]: ");
        scanf("%d", &voter);
        if (voter == -1)
            break;

        if (voter > 4 || voter < 1)
        {
            printf("There is no voter %d...\n", voter);
            continue;
        }

        printf("Voter %d, you are now part of the %s party Do you want to switch? ", voter, political_party[voters[voter - 1]]);
        scanf("%s", response);
        if (strcmp(response, "yes") == 0)
        {
            voters[voter - 1] = !voters[voter - 1];
            printf("Ok, you are now part of the %s party\n\n", political_party[voters[voter - 1]]);
        }
        else if (strcmp(response, "no") == 0)
            printf("Ok, you are still part of the %s party\n\n", political_party[voters[voter - 1]]);
    }

    printf("Exitting\n");
}
