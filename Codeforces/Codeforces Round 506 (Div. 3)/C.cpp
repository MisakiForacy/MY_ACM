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

void fxy_ac(){
    int n;
    cin >> n;
    vector<int> L(n), R(n), LL(n), RR(n);
    for (int i = 0;i < n;i ++){
        cin >> L[i] >> R[i];
        LL[i] = L[i];
        RR[i] = R[i];
    }
    sort(all(L), [&](int x,int y){
        return x > y;
    });
    sort(all(R));
    int Max = 0;
    for (int i = 0;i < n;i ++){
        int l = L[0], r = R[0];
        if (LL[i] == L[0]) l = L[1];
        if (RR[i] == R[0]) r = R[1];
        Max = max(Max, r - l);
    }
    cout << Max << '\n';
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