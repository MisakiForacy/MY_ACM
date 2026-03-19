#include <bits/stdc++.h>
using namespace std;
int st[5005];
struct haha{
    int u,v,k;
    bool operator < (const haha &that){
        return that.k > k;
    }
};
void init(int n){
    for (int i=1;i<=n;i++) st[i] = i;
}
int findx(int x){
    if (st[x]!=x) st[x] = findx(st[x]);
    return st[x];
}
void merge(int a,int b){
    a = findx(a);
    b = findx(b);
    st[a] = b;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<haha> lik(m);
    init(n);
    for (int i=0;i<m;i++){
        cin >> lik[i].u >> lik[i].v >> lik[i].k;
    }
    sort(lik.begin(),lik.end());
    int ans,cnt;
    ans = cnt = 0;
    for (int i=0;i<m;i++){
        if (findx(lik[i].u)!=findx(lik[i].v)){
            merge(lik[i].u,lik[i].v);
            ans += lik[i].k;
            cnt ++;
        }
    }
    if (cnt != n-1){
        cout << "orz\n";
    } else{
        cout << ans << '\n';
    }
}