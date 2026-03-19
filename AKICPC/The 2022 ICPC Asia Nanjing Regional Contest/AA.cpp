#include <iostream>
#include <vector>
#include <map>
using namespace std;

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
}

class CF {
    int n, m;
    vector<vector<int>> d;
public:
    CF(int _n, int _m) : n(_n), m(_m) {
        d = vector<vector<int>>(n + 1, vector<int>(m + 1, 0)); 
    }

    void add(int x1, int y1, int x2, int y2) {
        d[x1][y1] ++;
        if ( x2 + 1 <= n ) d[x2 + 1][y1] --;
        if ( y2 + 1 <= m ) d[x1][y2 + 1] --;

        if ( x2 + 1 <= n && y2 + 1 <= m ) d[x2 + 1][y2 + 1] ++;
    }

    void sum() {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            }
        }
    }

    int count(int x1, int y1, int x2, int y2, int x) {
        int res = 0;
        for (int i = x1;i <= x2;i ++) {
            for (int j = y1;j <= y2;j ++) {
                if ( d[i][j] == x ) res ++;
            }
        }
        return res;
    }

    void print() {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                cout << d[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

void solve() {
    int n, m, k, f = 1;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    CF D = CF(n, m);
    map<char, int>mp;
    int x1 = 1, y1 = 1, x2 = n, y2 = m;
    for (auto c : s) {
        if ( c == 'L' ) {
            if ( y1 > 1 ) y1 --;
            if ( !(-- y2) ) f = 0;
        }
        if ( c == 'R' ) {
            if ( y2 < m ) y2 ++;
            if ( ++ y1 > m ) f = 0;
        }
        if ( c == 'U' ) {
            if ( x1 > 1 ) x1 --;
            if ( !(-- x2) ) f = 0;
        }
        if ( c == 'D' ) {
            if ( x2 < n ) x2 ++;
            if ( ++ x1 > n ) f = 0;
        }

        if ( !f ) break;
    }

    if ( !f ) {
        cout << ((!k) ? n * m : 0) << "\n";
    }
    else {
        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
        int u = x1, d = x2, l = y1, r = y2, len = s.length();
        // vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        
        // vis[u][l] = 1;
        map<pair<int, int>, int> vis;
        vis[{u, l}] = 1;
        D.add(u, l, d, r);
        for (int i = len - 1;i >= 0;i --) {
            if ( s[i] == 'L' ) l ++, r ++;
            if ( s[i] == 'R' ) l --, r --;
            if ( s[i] == 'U' ) u ++, d ++;
            if ( s[i] == 'D' ) u --, d --;

            if ( vis[{u, l}] ) continue;
            vis[{u, l}] = 1;
            D.add(u, l, d, r);
        }

        D.sum();
        D.print();
        cout << D.count(x1, y1, x2, y2, area - k)  << "\n";
    }
}

int main() {
    IO();
    int t;
    cin >> t;
    while ( t -- ) solve();
    return 0;
}