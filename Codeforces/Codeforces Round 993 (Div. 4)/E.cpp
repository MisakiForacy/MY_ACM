#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL qpow(LL x,LL k){
	LL res = 1;
	while (k){
		if (k&1) res = res * x;
		x = x * x;
		k >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		LL k,l1,r1,l2,r2;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		LL n = 0;
		LL ans = 0;
		while (1){
			LL kn = qpow(k,n);
			if (kn > 1e9) break;
			LL add = max(0LL,min(r1,r2/kn)-max(l1-1,(l2-1)/kn));
			// cout << n << ' ' << kn << ' ' << add << '\n';
			ans += add;
			n ++;
		}
		cout << ans << '\n';
	}
}