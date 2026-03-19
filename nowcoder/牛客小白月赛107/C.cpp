#include <bits/stdc++.h>
using namespace std;
using LL = long long;
unsigned seed;
LL mp[200005][205];
set<int> c[205];
unsigned rnd(){
	unsigned ret=seed;
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n,m,k;
    cin >> n >> m >> k >> seed;
    LL op,a,b;
    LL ans = 0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            c[i].insert(j);
        }
    }
    for (int i=1;i<=k;i++){
        op = (rnd() % 2) + 1;
        if (op == 1){
            a = (rnd() % m) + 1;
            b = (rnd() % (n*m)) + 1;
            if (c[a].empty()) continue;
            for (auto &i:c[a]){
                mp[i][a] = b;
            }
            c[a].clear();
        }
        if (op == 2){
            a = (rnd() % n) + 1;
            b = (rnd() % m) + 1;
            c[b].insert(a);
            mp[a][b] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans ^= mp[i][j] * ((i-1)*m+j);
        }
    }
    cout << ans << '\n';
}