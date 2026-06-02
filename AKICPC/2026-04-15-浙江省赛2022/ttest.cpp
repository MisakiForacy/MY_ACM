#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    int n = 16;
    int a[] = {10, 4, 2, 1, 7, 3, 5, 12, 9, 8, 11, 10, 7, 4, 3, 3};
    int cnt[100000], mi = 10000, mx = -10000;
    for (int i = 0;i < n;i ++) 
    {
        cnt[a[i]] ++;
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    int index = 0;
    for (int i = mi;i <= mx;i ++) 
    {
        while (cnt[i] --) 
        {
            a[index] = i;
            index ++;
        }
    }
    for (int i = 0;i < n;i ++) cout << a[i] << ' ';
    cout << '\n';
}