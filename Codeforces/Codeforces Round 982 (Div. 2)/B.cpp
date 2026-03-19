#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n),f(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int Max = 0;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (a[j]<=a[i]){
                    f[i] ++;
                }
            }
            Max = max(Max,f[i]);
        }
        cout << n - Max << '\n';
    }
}