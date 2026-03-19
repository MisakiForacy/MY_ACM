#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    map<char,pair<int,int>>st;
    map<pair<int,int>,vector<int>>mp;
    st['W'] = {0,1}, st['A'] = {-1,0};
    st['S'] = {0,-1}, st['D'] = {1,0};
    string s;
    cin >> s;
    vector<int>prex(n+1,0),prey(n+1,0);
    for (int i=1;i<=n;i++){
        prex[i] = prex[i-1] + st[s[i-1]].first;
        prey[i] = prey[i-1] + st[s[i-1]].second;
        mp[{prex[i],prey[i]}].push_back(i);
    }
    for (int i=1;i<=n;i++){
        mp[{prex[n]-prex[i-1],prey[n]-prey[i-1]}]
    }
}