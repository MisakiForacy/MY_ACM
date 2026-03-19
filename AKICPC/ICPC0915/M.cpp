#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        map<pair<string,string>,bool> mp;
        map<string,int> cnt;
        for (int i=1;i<=n;i++){
            string a,b,c;
            cin >> a >> b >> c;
            if (c=="accepted"){
                if(!mp[{b,a}]){
                    cnt[b]++;
                    mp[{b,a}] = 1;
                }
            }
        }
        string ans;
        ans = ".";
        int k = 0;
        for(auto it:cnt){
            if(ans=="."){
                ans = it.first;
                k = it.second;
                continue;
            }
            if(k<it.second){
                k = it.second;
                ans = it.first;
            }
        }
        // cout<<"ans:";
        cout<<ans<<endl;
    }
}