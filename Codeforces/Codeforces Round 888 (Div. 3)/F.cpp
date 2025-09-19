#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 6e6 + 10;

int trie[N][2], p = 0, cnt = 1;
LL n, k;

void init(){
    for (int i = 0;i <= cnt;i ++){
        trie[i][0] = trie[i][1] = 0;
    }
    cnt = 1;
}

void insert(LL x){
    int p = 1;
    for (int i = k;i >= 0;i --){
        if (!trie[p][(x >> i) & 1]){
            trie[p][(x >> i) & 1] = ++ cnt;
        }
        p = trie[p][(x >> i) & 1];
    }
}

LL query(LL x){
    LL p = 1, ans = 0;
    for (int i = k;i >= 0;i --){
        if (trie[p][(x >> i) & 1]){
            if ((x >> i) & 1) ans += (1LL << i);
            p = trie[p][(x >> i) & 1];
        } else{
            if (!((x >> i) & 1)) ans += (1LL << i);
            p = trie[p][!((x >> i) & 1)];
        }
    }
    return ans;
}

void solve(){
    init();
    LL Max = -1, L, R, x;
    cin >> n >> k;
    vector<LL> a(n + 1, 0);
    cin >> a[1];
    insert(a[1]);
    for (int i = 2;i <= n;i ++){
        cin >> a[i];
        LL val = query(a[i]);
        LL xx = ((1LL << k) - 1) ^ a[i];
        if (((val ^ xx) & (a[i] ^ xx)) > Max){
            L = val;
            R = a[i];
            x = ((1LL << k) - 1) ^ a[i];
            Max = ((val ^ xx) & (a[i] ^ xx));
        }
        insert(a[i]);
    }
    for (int i = 1;i <= n;i ++){
        if (a[i] == L){
            L = i;
            break;
        }
    }
    for (int j = L + 1;j <= n;j ++){
        if (a[j] == R){
            R = j;
            break;
        }
    }
    cout << L << ' ' << R << ' ' << x << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}