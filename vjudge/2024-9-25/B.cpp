#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int h, m, s;
    cin >> h >> m >> s;
    h %= 12;
    int t = h * 3600 + m * 60 + s;
    int day = 12 * 3600;
    vector<int> d(n), rd(n);
    for(int i = 0; i < n; i ++)
    {
        int h1, m1, s1;
        cin >> h1 >> m1 >> s1;
        h1 %= 12;
        int t1 = h1 * 3600 + m1 * 60 + s1;
        d[i] = (t1 + day - t) % day;
    }
    sort(d.begin(), d.end());
    for(int i = 0; i < n; i ++)
    {
        rd[i] = day - d[i];
    }

    int ans = min(rd[0], d[n - 1]);
    for(int i = 1; i < n - 1; i ++)
    {
        ans = min(ans, d[i] * 2 + rd[i + 1]);
        ans = min(ans, rd[i] * 2 + d[i - 1]);
    }
    printf("%.2lf", 1.00 * ans * 6);
}