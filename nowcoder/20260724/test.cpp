#include <bits/stdc++.h>
using namespace std;
int t, x[100], a[100];
void dfs(int d, int i, int n)
{
    if (n == 1)
    {
        for (int k = 0; k < d; k++)
            printf("%4d", a[k]);
        printf("\n");
    }
    else
        for (int k = i; k < t; k++)
            if (n % x[k] == 0)
            {
                a[d] = x[k];
                dfs(d + 1, k, n / x[k]);
            }
}
int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 1; i--)
        if (n % i == 0)
            x[t++] = i;
    dfs(0, 0, n);
    return 0;
}
