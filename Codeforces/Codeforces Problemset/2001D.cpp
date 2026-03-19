#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> mp;
        vector<int> ans;
        for (int i=0;i<n;i++){
            cin >> a[i];
            mp[a[i]] ++;
            if (mp[a[i]]==1){
                ans.push_back(a[i]);
            }
        }
        for (int i=0;i<ans.size();i++){
            cout << ans[i] << " \n"[i==ans.size()-1];
        }
    }
}