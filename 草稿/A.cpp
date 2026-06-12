#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct P 
{
  LL id, v, ans;
  bool operator < (const P & T) const {
    return id < T.id;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<P> a(n);
  // cout << "ok\n";
  vector<int> use;
  for (int i = 0;i < n;i ++) {
    cin >> a[i].v;
    a[i].id = i;
    use.push_back(a[i].v);
  }
  sort(all(a), [&](P x, P y) {
    return x.v < y.v;    
  });
  sort(all(use));
  LL ans = 0;
  for (int i = 0;i < n;i ++) {
    ans += (a[i].v - a[0].v + 1);
  }
  // cout << ans << '\n';
  a[0].ans = ans;
  for (int i = 1;i < n;i ++) {
    LL pre = i;
    LL suf = n - pre;
    LL len = a[i].v - a[i - 1].v;
    a[i].ans = a[i - 1].ans - suf * len + pre * len;
  }
  sort(all(a)); 
  for (int i = 0;i < n;i ++) cout << a[i].ans << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  cin >> T;
  while (T --) solve();
}
