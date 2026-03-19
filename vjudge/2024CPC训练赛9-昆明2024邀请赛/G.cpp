#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n % 4 == 0 || n == 1){
            cout << "impossible\n";
        } else{
            vector<int> ans;
            ans.push_back(1);
            ans.push_back(0);
            for (int i=2;i<n;i++){
                ans.push_back(i);
            }
            for (int i=3;i<n;i+=4){
                swap(ans[i],ans[i+1]);
            }
            for (int i=0;i<n;i++){
                cout << ans[i] << " \n"[i==n-1];
            }
        }
    }
}