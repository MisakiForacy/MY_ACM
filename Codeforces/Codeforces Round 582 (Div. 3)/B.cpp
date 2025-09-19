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

struct RMQ{
    int n;
    vector<vector<int>> st;
    RMQ(int x = 1e5){
        n = x;
        st.resize(x + 1,vector<int>(21));
    }
    void build(vector<int> arr){
        for (int i = 1;i <= n;i ++){
            st[i][0] = arr[i];
        }
        for (int i = 1;i <= 20;i ++){
            for (int j = 1;j + (1LL << i) - 1 <= n;j ++){
                st[j][i] = min(st[j][i - 1],st[j + (1LL << i - 1)][i - 1]);
            }
        }
    }
    int query(int l,int r){
        int k = log2(r - l + 1);
        return min(st[l][k], st[r - (1LL << k) + 1][k]);
    }
};

void fxy_ac(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    RMQ st(n);
    st.build(a);
    int cnt = 0;
    for (int i = 1;i < n;i ++){
        if (a[i] > st.query(i + 1, n)){
            cnt ++;
        }
    }
    cout << cnt << '\n';
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