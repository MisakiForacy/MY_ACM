#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        int a[n+1];
        int id = 1;
        memset(a,0,sizeof(a));
        for (int i=k;i<=n;i+=k){
            a[i] = id ++;
        }
        for (int i=1;i<=n;i++){
            if (!a[i]){
                a[i] = id ++;
            }
        }
        for (int i=1;i<=n;i++){
            cout << a[i] << " \n"[i==n];
        }
    }
}