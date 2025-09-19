#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1;i <= n;i ++) cin >> x[i] >> y[i];
    for (int i = 1;i <= n;i ++){
        int id;
        double Min = 1e18;
        for (int j = 1;j <= n;j ++){
            if (i == j) continue;
            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            if (d < Min){
                Min = d;
                id = j;
            }
        }
        cout << id << " \n"[i == n];
    }
}

int main(){
    int T = 1;
    // cin >> T;
    while (T --) solve();
}