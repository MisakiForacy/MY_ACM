#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,x,mx;
        memset(a,0,sizeof(a));
        cin >> n;
        mx = 0;
        for (int i=0;i<n;i++){
            cin >> x;
            a[x] ++;
            mx = max(mx,a[x]);
        }
        cout << n - mx << '\n';
    }
}