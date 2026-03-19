#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>ar(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        int ans = ar[n];
        for (int i=n-1;i>=1;i--){
            ans = max(ar[i],ans+1);
        }
        cout << ans << '\n';
    }
}