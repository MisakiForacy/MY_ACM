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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    if (a[1] == a[n]){
        int cnt = 0;
        for (int i = 1;i <= n;i ++){
            if (a[i] == a[1]){
                cnt ++;
            }
        }
        cout << (cnt >= k ? "YES\n" : "NO\n");
    } else{
        int cnt = 0, id = -1;
        for (int i = 1;i <= n;i ++){
            if (a[i] == a[1]){
                cnt ++;
            }
            if (cnt == k){
                id = i + 1;
                break;
            }
        }
        int c2 = 0;
        for (int i = n;i >= id;i --){
            if (a[i] == a[n]){
                c2 ++;
            }
        }
        if (cnt == k && c2 >= k){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
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