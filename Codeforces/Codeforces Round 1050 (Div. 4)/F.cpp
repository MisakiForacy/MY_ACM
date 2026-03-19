#include <bits/stdc++.h>
#define x first
#define y second
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n, m = 0;
    cin >> n;
    vector<vector<LL>> a(n);
    for (int i = 0;i < n;i ++) {
        int k, x;
        cin >> k;
        for (int j = 0;j < k;j ++) {
            cin >> x;
            a[i].push_back(x);
        }
        m = max(m, k);
    }
    vector<int> lst;
    for (int i = 0;i < m;i ++) {
        LL Min = inf;
        vector<int> cur;
        if (lst.empty())
            for (int j = 0;j < n;j ++)
                if (i < siz(a[j]))
                    lst.push_back(j);
        for (auto x : lst) Min = min(Min, a[x][i]);
        int ok = 1;
        for (auto x : lst) {
            if (siz(a[x]) > i && a[x][i] == Min)
                cur.push_back(x);
            if (siz(a[x]) == i + 1 && a[x][i] == Min) ok = 0;    
        }
        if (!ok) cur.clear();
        lst = cur;
        cout << Min << ' ';
    }
    cout << '\n';
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}