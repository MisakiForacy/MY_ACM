#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

struct DSU{
    vector<int> dsu;
    vector<int> siz;
    int n;
    DSU(int len = 1e5){
        n = len;
        dsu.resize(n+1,0);
        siz.resize(n+1,1);
    }
    void init(){
        for (int i = 1;i <= n;i ++) dsu[i] = i;
        for (int i = 0;i <= n;i ++) siz[i] = 1;
    }
    int findx(int x){
        if (dsu[x] != x){
            siz[x] += siz[dsu[x]];
            dsu[x] = findx(dsu[x]);
        }
        return dsu[x];
    }
    void merge(int a,int b){
        a = findx(a);
        b = findx(b);
        if (a < b) swap(a,b);
        if (a != b){
            dsu[a] = b;
            siz[b] += siz[a];
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<int> b;
        DSU f(100);
        f.init();
        int ans = 0;
        for (int i = 1;i <= n;i ++) cin >> a[i];
        for (int i = 1;i <= n - k;i ++){
            int Min = 500;
            int id = 0;
            for (int j = 2;j <= n;j ++){
                if (f.findx(j) != f.findx(j - 1) && abs(a[j] - a[j - 1]) < Min){
                    Min = abs(a[j] - a[j - 1]);
                    id = j;
                }
            }
            ans += abs(a[id] - a[id - 1]);
            f.merge(id, id - 1);
        }
        cout << ans << '\n';
    }
}