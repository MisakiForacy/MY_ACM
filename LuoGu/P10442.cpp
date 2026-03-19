#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    solve();
}
void solve(){
    string s,t;
    int cnt = 0,idx;
    cin >> s >> t;
    if(s.length() > t.length())swap(s,t);
    for(int i=0;i<(int)s.length();i++){
        if((int)t.find(s[i])!=-1){
            cnt ++;
            idx = t.find(s[i]);
            t.erase(idx,1);
        }
    }
    cout << cnt;
}