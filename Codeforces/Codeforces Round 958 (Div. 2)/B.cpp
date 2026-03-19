#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string ss,s="";
        cin >> ss;
        int ff = 0;
        for (int i=0;i<n;i++){
            if (ss[i]=='0'&&!ff){
                ff = 1;
                s.push_back('0');
            } else if (ss[i]=='1'){
                ff = 0;
                s.push_back('1');
            }
        }
        n = s.length();
        vector<int>ar(n+1),pre(n+1,0);
        for (int i=1;i<=n;i++){
            ar[i] = s[i-1]-'0';
            pre[i] = pre[i-1] + ar[i];
        }
        if (pre[n]>n/2){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}