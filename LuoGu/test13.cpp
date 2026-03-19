#include <stdio.h>
#include <string.h>

struct
{
    char name[100];
    int score;
} sheet[100];

// char job[12][21] = {"Doctor", "Lawyer", "Charitarian", "Gardener", "Magician", "Machinist", "LuckyDog", "Adventurer", "Mercenary", "Blind Girl", "AirForce", "Pioneer"};

int main()
{
    int days, times, sc, i, j, k, l, flag;
    char na[21];

    flag = 0;
    l = 0;

    scanf("%d", &days);
    for (i = 0; i < days; i++)
    {
        scanf("%d", &times);
        for (j = 0; j < times; j++)
        {
            scanf("%s", na);
            scanf("%d", &sc);
            // for (k = 0; k < 12; k++)
            //     if (strcmp(na, job[k]) != 0)
            //     {
            //         flag = 1;
            //         break;
            //     }
            // if (flag)
            // {
            for (k = 0; k < 12; k++)
                if (strcmp(na, sheet[k].name) == 0)
                {
                    sheet[k].score += sc;
                    flag = 0;
                    break;
                }
            // }
            // if (flag)
            // {
            strcpy(sheet[l].name, na);
            sheet[l].score = sc;
            l++;
            // }
        }
    }
    flag = 1;
    for (i = 0; i < 12; i++)
    {
        if (sheet[i].score >= 2000)
        {
            printf("%s\n", sheet[i].name);
            flag = 0;
        }
    }
    if (flag)
        printf("NOTHING");
    return 0;
}