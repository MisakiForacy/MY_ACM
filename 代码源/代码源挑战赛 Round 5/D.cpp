#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    string n;
    LL m, k;
    cin >> n >> m >> k;
    LL v = 0;
    if (k --){
        for (int i = 0;i < siz(n);i ++){
            v += n[i] - '0';
        }
        v += m;
    }
    if (k --){
        n = to_string(v);
        v = 0;
        for (int i = 0;i < siz(n);i ++){
            v += n[i] - '0';
        }
        v += m;
    }
    if (k --){
        n = to_string(v);
        v = 0;
        for (int i = 0;i < siz(n);i ++){
            v += n[i] - '0';
        }
        v += m;
    }
    vector<int> lop;
    map<int, int> mp;
    while (k --){
        int vv = v;
        v = 0;
        while (vv){
            v += vv % 10;
            vv /= 10;
        }
        v += m;
        if (mp.count(v)) break;
        mp[v] ++;
        lop.push_back(v);
    }
    if (siz(lop)){
        cout << lop[k % siz(lop)] << '\n';
    } else{
        cout << v << '\n';
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}