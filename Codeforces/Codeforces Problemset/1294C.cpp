#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        vector<ll>ans(0);
        for (int i=2;i<sqrt(n);i++){
            if (n%i==0){
                ans.push_back(i);
                n /= i;
                for (int j=i+1;j<=sqrt(n);j++){
                    if (n%j==0){
                        ans.push_back(j);
                        n /= j;
                        ans.push_back(n);
                    }
                }
                break;
            }
        }
        if (ans.size()<3||ans[0]==ans[1]||ans[1]==ans[2]){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            for (int i=0;i<3;i++){
                cout << ans[i] << " \n"[i==2];
            }
        }
    }
}