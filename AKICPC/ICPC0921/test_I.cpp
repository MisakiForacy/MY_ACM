#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i<=b;i++)

// const int N = 1e6+10;
int ans[33];
int n;

void dfs(int sum,int pos,int last){
    ans[pos] = last;
    if(sum==n && pos==31) {
        cout<<"YES"<<endl;
        int cnt = 0;
        rep(i,0,31){
            cnt++;
            cout<<ans[i]<<" ";
            if(cnt==8) {
                cnt = 0;
                cout<<endl;
            }
        }
        cout<<endl;
        return;
    }

    if(sum>n || pos>31) return;
    dfs(sum+pow(2,pos),pos+1,1);
    dfs(sum-pow(2,pos),pos+1,-1);
    if(last != 0) dfs(sum,pos+1,0);

}

void solve(){
    cin>>n;
    dfs(1,0,1);
    dfs(0,0,0);
    dfs(-1,0,-1);
}

signed main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
