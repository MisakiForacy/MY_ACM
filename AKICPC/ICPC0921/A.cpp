#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
struct haha{
    ll score,index,rank;
    string name;
};
int main(){
    ll n,k,x,reg = 1e9;
    cin >> n >> k;
    vector<haha> node(n);
    for (int i=0;i<k;i++){
        cin >> x;
        reg = min(reg,x);
    }
    for (int i=0;i<n;i++){
        cin >> node[i].score >> node[i].name;
        node[i].index = i+1;
    }
    sort(all(node),[&](haha x,haha y){
        return x.score > y.score;
    });
    map<string,ll> mp;
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (mp[node[i].name] < reg) cnt ++;
        mp[node[i].name] ++;
        node[i].rank = cnt;
    }
    sort(all(node),[&](haha x,haha y){
        return x.index < y.index;
    });
    for (int i=0;i<n;i++){
        cout << node[i].rank << '\n';
    }
}