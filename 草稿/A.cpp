#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
  int n;
  cin >> n;
  vector<LL> a(n + 1), p(n + 1, 0);
  for (int i = 1;i <= n;i ++) cin >> a[i];
  sort(a.begin() + 1, a.end());
  for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
  LL ans = p[n];
  for (int i = 1;i <= n;i ++) {
    ans = min(ans, p[i] + max(p[n] - p[i] - i, 0LL));
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T --) solve();
}
