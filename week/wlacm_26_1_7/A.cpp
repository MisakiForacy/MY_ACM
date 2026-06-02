#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = n / 3;
    map<char, int> mp, cnt;
    mp['0'] = count(s.begin(), s.end(), '0');
    mp['1'] = count(s.begin(), s.end(), '1');
    mp['2'] = count(s.begin(), s.end(), '2');
    if (mp['0'] < m) {
        for (int i = 0;i < n;i ++) {
            if (s[i] == '1' && mp['1'] > m) {
                mp['0'] ++, s[i] = '0', mp['1'] --;
            } else if (s[i] == '2' && mp['2'] > m) {
                mp['0'] ++, s[i] = '0', mp['2'] --;
            }
            if (mp['0'] == m) break;
        }
    }
    if (mp['1'] < m) {
        int cnt = 0;
        for (int i = 0;i < n;i ++) {
            if (s[i] == '0') cnt ++;
            if (s[i] == '0' && mp['0'] > m && cnt > m) {
                mp['1'] ++, s[i] = '1', mp['0'] --;
            } else if (s[i] == '2' && mp['2'] > m) {
                mp['1'] ++, s[i] = '1', mp['2'] --;
            }
            if (mp['1'] == m) break;
        }
    }
    if (mp['2'] < m) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0;i < n;i ++) {
            if (s[i] == '0') cnt0 ++;
            if (s[i] == '1') cnt1 ++;
            if (s[i] == '0' && mp['0'] > m && cnt0 > m) {
                mp['2'] ++, s[i] = '2', mp['0'] --;
            } else if (s[i] == '1' && mp['1'] > m && cnt1 > m) {
                mp['2'] ++, s[i] = '2', mp['1'] --;
            }
            if (mp['2'] == m) break;
        }
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

/*
1 2 3 4
5 6 7 8
9

9 2 3 4
5 6 7 8
1

9 1 2 3
4 5 6 7
8
*/