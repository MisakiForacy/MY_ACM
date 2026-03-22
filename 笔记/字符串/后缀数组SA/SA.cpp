#include <bits/stdc++.h>
using namespace std;

string s = "aabaaaab";

void SA(string s, vector<int>&sa, vector<int>&rk) {
    int n = s.size();
    s = ' ' + s;
    sa.resize(n + 1), rk.resize(2 * n + 1);
    for (int i = 1;i <= n;i ++) sa[i] = i, rk[i] = s[i];
    for (int j = 1;j < n;j <<= 1) {
        sort(sa.begin() + 1, sa.end(), [&](int x, int y) {
            return rk[x] == rk[y] ? rk[x + j] < rk[y + j] : rk[x] < rk[y];
        });
        vector<int> tp = rk;
        for (int p = 0, i = 1;i <= n;i ++) {
            if (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + j] == tp[sa[i - 1] + j]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++ p;
            }
        }
    }
    for (int i = 1;i <= n;i ++) cout << sa[i] << ' ';
    cout << '\n';
    for (int i = 1;i <= n;i ++) cout << rk[i] << ' ';
    cout << '\n';
}

int main() {
    vector<int> sa, rk;
    SA(s, sa, rk);
}