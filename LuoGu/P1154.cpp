#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
int a[N], b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int Max = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        Max = max(Max,a[i]);
    }
    sort(a,a+n);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            b[a[j]-a[i]] = 1;
        }
    }
    int ans;
    for (ans=n;ans<=Max;ans++){
        int ok = 1;
        for (int w=1;w*ans<=Max;w++){
            if (b[w*ans]){
                ok = 0;
                break;
            }
        }
        if (ok){
            break;
        }
    }
    cout << ans << '\n';
}