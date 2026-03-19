#include <bits/stdc++.h>
using namespace std;
bool is_pal(string s){
    int len = s.length();
    for (int i=0;i<len/2;i++){
        if (s[i]!=s[len-i-1]){
            return 0;
        }
    }
    return 1;
}
bool check(string s,int n,int k){
    // cout << s << ':' << '\n';
    for (int i=0;i<=n-k;i++){
        // cout << s.substr(i,k) << "    " << is_pal(s.substr(i,k)) << '\n';
        if (is_pal(s.substr(i,k))){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,k;
    int cnt = 0;
    string s;
    cin >> n >> k;
    cin >> s;
    map<string,int>mp;
    sort(s.begin(),s.end());
    do{
        if (!mp[s] && check(s,n,k)){
            // cout << s << ">ok" << '\n';
            cnt ++;
            mp[s] ++;
        }
    } while (next_permutation(s.begin(),s.end()));
    cout << cnt << '\n';
}