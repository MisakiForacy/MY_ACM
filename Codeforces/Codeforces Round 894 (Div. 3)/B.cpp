#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD = 1e9 + 7;

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int m;
        cin >> m;
        vector<int> a(m),b;
        for (int i = 0;i < m;i ++) cin >> a[i];
        b.push_back(a[0]);
        for (int i = 1;i < m;i ++){
            if (a[i] >= a[i - 1]){
                b.push_back(a[i]);
            } else{
                b.push_back(a[i]);
                b.push_back(a[i]);
            }
        }
        cout << b.size() << '\n';
        for (int i = 0;i < b.size();i ++){
            cout << b[i] << " \n"[i == b.size() - 1];
        }
    }
}