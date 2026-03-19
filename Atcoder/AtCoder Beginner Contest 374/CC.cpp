#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    int a[n];
    LL tot = 0;
    for (int i=0;i<n;i++) cin >> a[i], tot += a[i];
    LL mid = tot / 2 + tot % 2;
    LL Max = LLONG_MIN;
    for (int i=0;i<(1<<n);i++){
        LL sum = 0;
        LL num = i;
        int idx = 0;
        for (int j=0;j<n;j++){
            sum += a[j] * ((i >> j) & 1);
        }
        if (sum <= mid){
            Max = max(Max,sum);
        }
    }
    cout << max(Max,tot-Max) << '\n';
}