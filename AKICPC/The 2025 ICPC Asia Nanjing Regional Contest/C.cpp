#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL n;
    cin >> n;
    if (n & 1)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        cout << n / 2 << ' ' << n / 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}