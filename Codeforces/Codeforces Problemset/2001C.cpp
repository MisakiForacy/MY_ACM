#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int ask(int a,int b){
    cout << "? " << a << ' ' << b << '\n';
    int x; cin >> x;
    return x;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<pair<int,int>> ans;
        for (int i=2;i<=n;i++){
            int id = 1;
            int x = ask(id,i);
            while (x != id){
                id = x;
                x = ask(id,i);
            }
            ans.push_back({id,i});
        }
        cout << "! ";
        for (int i=0;i<ans.size();i++){
            cout << ans[i].first << ' ' << ans[i].second << " \n"[i==ans.size()-1];
        }
    }
}