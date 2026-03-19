#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
bool check(vector<int> a,int n,int k){
    int mx = 0, mi = inf;
    for (int i=1;i<=n-k+1;i++){
        int sum = 0;
        for (int j=i;j<i+k;j++){
            sum += a[j];
        }
        mx = max(mx,sum);
        mi = min(mi,sum);
        cout << i << ':' << sum << '\n';
    }
    cout << mx << ' ' << mi << '\n';
    return (mx - mi <= 1);
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1);
        int t = 1;
        for (int i=1;i<=k;i++){
            if (i&1){
                for (int j=i;j<=n;j+=k){
                    a[j] = t++;
                }
            } else{
                for (int j=i;j<=n;j+=k){
                    a[j] = t++;
                }
                int temp = t;
                for (int j=i;j<=n;j+=k){
                    a[j] = --t;
                }
                t = temp;
            }
        }
        for (int i=1;i<=n;i++){
            cout << a[i] << " \n"[i==n];
        }
        // int ok = check(a,n,k);
        // cout << ok << '\n';
    }
}