#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,f = 0; // f 表示重新递增
        cin >> n;
        vector<ll>ar(n),nar;
        vector<ll>ans(n);
        cin >> ar[0];
        nar.push_back(ar[0]);
        ans[0] = 1;
        for (int i=1;i<n;i++){
            cin >> ar[i];
            if (f){
                if (ar[i]>nar[0] || ar[i]<nar[nar.size()-1]){
                    ans[i] = 0;
                } else{
                    nar.push_back(ar[i]);
                    ans[i] = 1;
                }
            } else{
                if (ar[i]>=nar[nar.size()-1]){
                    nar.push_back(ar[i]);
                    ans[i] = 1;
                } else if (ar[i]<nar[nar.size()-1] && ar[i]<=nar[0]){
                    nar.push_back(ar[i]);
                    ans[i] = 1;
                    f = 1;
                } else{
                    ans.push_back(0);
                }
            }
            // cout << ar[i] << ":" << ans[i] << '\n';
        }
        for (int i=0;i<n;i++){
            cout << ans[i];
        } 
        cout << '\n';
    }
}