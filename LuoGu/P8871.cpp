#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int len = 0;
    string s;
    vector<pair<string,int>>mp;
    while (getline(cin,s)){
        len ++;
        mp.push_back({s,len});
    }
    int t = to_string(len).length();
    for (int i=0;i<mp.size();i++){
        int sp = t - to_string(mp[i].second).length();
        string spc = "";
        for (int j=0;j<sp;j++){
            spc.push_back(' ');
        }
        spc.append(to_string(mp[i].second));
        spc.push_back(' ');
        mp[i].first = spc + mp[i].first;
        cout << mp[i].first << '\n';
    }
}