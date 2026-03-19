#include<iostream>
#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define tans cout<<"答案:"
#define rep(i,a,b) for(int i = a;i<=b;i++)
const int N = 1e6 + 10;
//负数求模公式 (a % mod + mod) % mod

void solve() {
	int n, k; cin >> n >> k;
	int t = pow(2, k) - 1;
	int cnt = 0;
	rep(a, 0, t) {
		rep(b, 0, t) {
			rep(c, 0, t) {
				rep(d, 0, t) {
					int temp = (((a & b) ^ c) | d);
					if (temp==n) {
						cnt++;
						cout << "a:" << a << " " << "b:" << b << " c:" << c << " d:" << d << endl;
					}
					else {
						cout << "这个不行: ";
						cout << "a:" << a << " " << "b:" << b << " c:" << c << " d:" << d << endl;

					}
				}
			}
		}
	}
	cout << cnt << endl;
}

signed main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}