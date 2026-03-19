#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    while (cin >> a >> b >> c){
        string n;
        vector<string>la,lb,lc,ans;
        for (int i=0;i<a;i++){
            cin >> n;
            la.push_back(n);
        }
        for (int i=0;i<b;i++){
            cin >> n;
            lb.push_back(n);
        }
        for (int i=0;i<c;i++){
            cin >> n;
            lc.push_back(n);
        }
        for (int i=0;i<b;i++){
            if (find(lc.begin(),lc.end(),lb[i])==lc.end()&&find(la.begin(),la.end(),lb[i])!=la.end()){
                ans.push_back(lb[i]);
            }
        }
        if (ans.empty()){
            cout << "No enemy spy\n";
        } else{
            for (int i=0;i<ans.size();i++){
                cout << ans[i] << " \n"[i==ans.size()-1];
            }
        }
    }
}