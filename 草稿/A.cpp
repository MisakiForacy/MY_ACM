#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a, b(n + 1, 0), ans(n + 1, 0);
  ans[1] = 1;
  int k, x;
  cin >> k;
  for (int i = 1;i <= k;i ++) {
    cin >> x;
    b[x] = 1;
    ans[x] = 1;
  }
  for (int i = 1;i <= n - 1;i ++) {
    cin >> k;
    for (int j = 1;j <= k;j ++) {
      cin >> x;
      if (b[i]) ans[x] = 1;
    }
  }
  int sum = 0;
  for (int i = 1;i <= n;i ++) sum += ans[i];
  cout << sum << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T --) solve();
}
