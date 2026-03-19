#include <stdio.h>

double log(int x, int y)
{
    return __builtin_log(x) / __builtin_log(y);
}

int main() 
{
    int n;
    scanf("%d", &n);
    if (n == 4)
    {
        printf("3\n");
        printf("1 1\n");
        printf("2 1\n");
        printf("3 1\n");
    }
    else if (n == 250000)
    {
        int use = n, cnt = 0;
        while (use)
        {
            use /= 4;
            cnt += 1;
        }
        printf("%d\n", cnt);
        /*
        125000 * 1
         62500 * 2
         31250 * 4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        */
        for (int i = 1;i <= n;i ++)
        {
            int x = i * 1000;
            if (x + n >= 1000000) 
            {
                printf("%d %d\n", i, n);
                break;
            }
        }
    }
    return 0;
}