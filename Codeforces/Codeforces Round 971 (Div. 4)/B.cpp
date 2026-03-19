#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n;
        vector<int> ans;
        for (int i=1;i<=n;i++){
            cin >> s;
            for (int j=1;j<=4;j++){
                if (s[j-1]=='#'){
                    ans.push_back(j);
                    break;
                }
            }
        }
        for (int i=n-1;i>=0;i--){
            cout << ans[i] << " \n"[i==0];
        }
    }
}