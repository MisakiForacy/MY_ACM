#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info{
    string s;
    ll p;
};
bool cmp(info a,info b){
    return a.p > b.p;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<info>as,ah;
    string s;
    char t;
    ll p;
    for (int i=0;i<n+m;i++){
        cin >> s >> t >> p;
        if (t=='H'){
            ah.push_back({s,p});
        } else{
            as.push_back({s,p});
        }
    }
    sort(as.begin(),as.end(),cmp);
    sort(ah.begin(),ah.end(),cmp);
    cout << ah[2].s << '\n';
    for (int i=5;i<9;i++){
        cout << as[i].s << '\n';
    }
}