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

struct node{
    int x,y;
};

void fxy_ac(){
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i].x;
    for (int i = 0;i < n;i ++) cin >> a[i].y;
    sort(all(a),[&](node a,node b){
        return a.x < b.x;
    });
    for (int i = 0;i < n;i ++){
        cout << a[i].x << " \n"[i == n - 1];
    }
    for (int i = 0;i < n;i ++){
        cout << a[i].y << " \n"[i == n - 1];
    }
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