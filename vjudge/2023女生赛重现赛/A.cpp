#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

struct node
{
    int i, j, op, a, b, d, v;
};


void fxy_ac() {
    vector<vector<int>> p(15);
    map<int, int> mp;
    mp[1] = 2, mp[2] = 3, mp[3] = 4;
    p[2].push_back(1), p[3].push_back(2), p[4].push_back(3);
    for (int i = 1;i <= 12;i ++) {
        int a, b;
        cin >> a >> b;
        int cur = mp[a];
        int id;
        for (int i = 0;i < siz(p[cur]);i ++) {
            if (p[cur][i] == a) {
                id = i;
                break;
            }
        }
        for (int i = id;i < siz(p[cur]);i ++) {
            p[cur + b].push_back(p[cur][i]);
            mp[p[cur][i]] = cur + b;
        }
        int m = siz(p[cur]);
        for (int i = id;i < m;i ++) {
            p[cur].pop_back();
        }
    }
    cout << (siz(p[9]) == 3 ? "Y\n" : "N\n");
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}