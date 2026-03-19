#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 4005;
vector<int> s;
vector<int> init(int n){
    vector<int> a(n+1,0);
    iota(a.begin(),a.end(),0);
    return a;
}
int findx(int x){
    if (s[x] != x){
        s[x] = findx(s[x]);
    }
    return s[x];
}
void merge(int x,int y){
    if (x < y) swap(x,y);
    x = findx(x), y = findx(y);
    s[x] = y;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,u,v;
        cin >> n >> m;
        s = init(n);
        vector<int> cnt(n+1,0);
        for (int i=0;i<m;i++){
            cin >> u >> v;
            if (findx(u) == findx(v)){
                cnt[u] ++;
                cnt[v] ++;
            }
            merge(u,v);
        }
        int ok = 1;
        for (int i=1;i<=n;i++){
            cout << cnt[i] << " \n"[i==n];
            if (cnt[i] > 2){
                ok = 0;
            }
        }
        if (!ok){
            cout << -1 << '\n';
        } else{
            cout << 1 << '\n';
        }
    }
}

/*
 1: 3 5
 2: 1 8.
 3: 5 8.
 4: 4 9.
 5: 6 7.
 6: 7 9.
 7: 1 2.
 8: 1 4.
 9: 2 4.
10: 4 6.
4 10 2 8 7 9 6 5 3 1
*/