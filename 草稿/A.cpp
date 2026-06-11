#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
  string s;
  cin >> s;
  s = ' ' + s;
  int r = siz(s), l;
  vector<int> p(siz(s), 0);
  for (int i = 1;i < siz(s);i ++) p[i] = s[i] - '0';
  for (int i = siz(s) - 1;i >= 1;i --) {
    l = i;
    if (p[i] >= 5) {
      l = i - 1;
      p[i - 1] += 1;
      r = i;
    }
  }
  for (int i = l;i < r;i ++) cout << p[i];
  for (int i = r;i < siz(s);i ++) cout << 0;
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  cin >> T;
  while (T --) solve();
}
