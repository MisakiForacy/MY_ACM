#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> f(N, 0), cnt(N, 0);
    auto upd = [&](int x, int v) -> void {
        for (;x < N;x += lowbit(x)) f[x] += v;
    }; 
    auto qry = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f[x];
        return sum;
    };
    auto ask = [&](int l, int r) -> int {
        return qry(r) - qry(l - 1);
    };
    int r = 1;
    vector<int> pos(N, 0);
    set<int> st;
    stack<pair<char, int>> opt;
    vector<int> A(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        char op;
        int x;
        cin >> op;
        if (op == '+' || op == '-') {
            cin >> x;
            if (op == '+') {
                opt.push({'+', x});
                A[r ++] = x;
                if (!pos[x]) {
                    pos[x] = r - 1;
                    upd(r - 1, 1);
                }
            } else {
                opt.push({'-', x});
                r -= x;
            }
        } else {
            if (op == '!') {
                auto [opp, v] = opt.top();
                opt.pop();
                if (opp == '+') {
                    r -= 1;
                    if (pos[A[r]] == r) {
                        
                    } 
                } else {
                    r += v;
                }
            } else if (op == '?') {
                cout << ask(1, r - 1) << '\n';
            }
        }
    }
}