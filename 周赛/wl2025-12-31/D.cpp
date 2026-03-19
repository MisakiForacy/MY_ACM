#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int Mi = 1000;
    auto vaild = [&](vector<int> b) -> bool {
        return (b[0] + b[1] > b[2] && b[0] + b[2] > b[1] && b[1] + b[2] > b[0]);
    };
    for (int j = 0;j < 3;j ++) {
        vector<int> b = a;
        for (int i = a[j];i <= a[j] + 100;i ++) {
            b[j] = i;
            if (vaild(b)) {
                Mi = min(Mi, i - a[j]);
                break;
            }
        }
    }
    cout << Mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve(); 
}