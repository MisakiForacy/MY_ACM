#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

struct Trie{
    struct edge{
        int son[26];
        LL end;
        void init(){
            for (int i = 0;i < 26;i ++){
                son[i] = -1;
            }
            end = -1;
        }
    };
    vector<edge> tr;
    int nxt;
    char st;
    Trie(int x = 1e5 + 10, char c = 'a'){
        tr.resize(x);
        nxt = 0;
        st = c;
    }
    void insert(string s, LL w){
        int p = 0;
        // tr[p].init();
        for (int i = 0;i < s.size();i ++){
            if (tr[p].son[s[i] - st] == -1){
                tr[p].son[s[i] - st] = ++ nxt;
                tr[nxt].init();
            }
            p = tr[p].son[s[i] - st];
        }
        tr[p].end = w;
    }
    LL query(string s){
        int p = 0;
        for (int i = 0;i < s.size();i ++){
            if (tr[p].son[s[i] - st] != -1){
                p = tr[p].son[s[i] - st];
            } else{
                return -1;
            }
        }
        return tr[p].end;
    }
};

Trie tr(4e6 + 20, 'a');

void fxy_ac(){
    LL n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n + 2, vector<char> (n + 2, '#'));
    for (int i = 1;i <= n * n + 1;i ++){
        for (int j = 0;j < 26;j ++){
            tr.tr[i].son[i] = -1;
        }
        tr.tr[i].end = -1;
    }
    tr.nxt = 0;
    tr.tr[0].init();
    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= n;j ++){
            char c; cin >> c;
            mp[i][j] = c;
        }
    }
    for (int i = 1;i <= m;i ++){
        string s;
        LL w;
        cin >> s >> w;
        tr.insert(s, w);
    }
    LL ans = 0;
    int ok = 1;
    for (int i = 1;i <= n;i ++){
        string s = "";
        for (int j = 1;j <= n + 1;j ++){
            if (mp[i][j] == '#'){
                if (s.size()){
                    LL x = tr.query(s);
                    if (x == -1){
                        cout << -1 << '\n';
                        return;
                    } else{
                        ans += x;
                    }
                    s = "";
                    continue;
                }
            } else{
                s.push_back(mp[i][j]);
            }
        }
    }
    for (int j = 1;j <= n;j ++){
        string s = "";
        for (int i = 1;i <= n + 1;i ++){
            if (mp[i][j] == '#'){
                if (s.size()){
                    LL x = tr.query(s);
                    // cout << s << ' ' << x << '\n';
                    if (x == -1){
                        cout << -1 << '\n';
                        return;
                    } else{
                        ans += x;
                    }
                    s = "";
                    continue;
                }
            } else{
                s.push_back(mp[i][j]);
            }
        }
    }
    cout << ans << '\n';
    return;
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}