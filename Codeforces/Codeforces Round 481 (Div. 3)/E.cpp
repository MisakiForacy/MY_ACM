#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,w;
    cin >> n >> w;
    LL Max = 0, Min = 0;
    LL a = 0, x;
    for (int i = 1;i <= n;i ++){
        cin >> x;
        a += x;
        Max = max(Max, a);
        Min = min(Min, a);
    }
    LL lo = Min, hi = w - Max;
    cout << max(0LL,hi + lo + 1) << '\n';
}