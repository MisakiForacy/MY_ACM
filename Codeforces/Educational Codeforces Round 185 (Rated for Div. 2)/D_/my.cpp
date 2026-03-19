#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve () {
    LL n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s + ' ';
    string tmpStr = s;
    int Cnt = 0;
    for (int i = 1;i <= n;i ++) 
        if (tmpStr[i] == '?') 
            tmpStr[i] = 'I', Cnt ++;
    LL Sum = 0;
    for (int i = 1;i <= n;i ++) {
        if (tmpStr[i] == 'I') {
            if (tmpStr[i + 1] == 'X' || tmpStr[i + 1] == 'V') {
                Sum -= 1;
            } else {
                Sum += 1;
            }
        } else if (tmpStr[i] == 'X') {
            Sum += 10;
        } else if (tmpStr[i] == 'V') {
            Sum += 5;
        }
    }
    // cout << Sum << '\n';
    vector<pair<int, int>> pos(n + 1, {5 * n, 0});
    for (int i = 1;i <= n;i ++) pos[i].second = i;
    string Tmp = tmpStr;
    int Cur = 1;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '?' && Tmp[i] == 'I') {
            if (Tmp[i - 1] == 'I' && (Tmp[i + 1] != 'X' && Tmp[i + 1] != 'V')) {
                pos[i].first = Cur ++;
                Tmp[i] = 'X';
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '?' && Tmp[i] == 'I') {
            if (Tmp[i - 1] == 'I') {
                pos[i].first = Cur ++;
                Tmp[i] = 'X';
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '?' && Tmp[i] == 'I') {
            if (Tmp[i + 1] != 'X' && Tmp[i + 1] != 'V') {
                pos[i].first = Cur ++;
                Tmp[i] = 'X';
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '?' && Tmp[i] == 'I') {
            pos[i].first = Cur ++;
            Tmp[i] = 'X';
        }
    }
    sort(pos.begin() + 1, pos.end());
    vector<LL> dp(n + 1, 0);
    dp[0] = Sum;
    for (int i = 1;i <= n;i ++) {
        if (pos[i].first > 4 * n) break;
        int cur = pos[i].second, pre = pos[i].second - 1, nxt = pos[i].second + 1;
        tmpStr[cur] = 'X';
        dp[i] = dp[i - 1] - ((tmpStr[nxt] == 'X' || tmpStr[nxt] == 'V') ? -1 : 1) + 10;
        if (tmpStr[pre] == 'I') dp[i] -= 2;
    }
    while (q --) {
        LL cx, cv, ci;
        cin >> cx >> cv >> ci;
        LL Need = max(0LL, Cnt - ci);
        cout << dp[Need] - min(cv, Need) * 5 << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}