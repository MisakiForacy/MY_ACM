#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		LL m,a,b,c;
		cin >> m >> a >> b >> c;
		LL m1 = m, m2 = m;
		m1 -= min(m,a);
		m2 -= min(m,b);
		cout << 2*m - max(m1+m2-c,0LL) << '\n';
	}
}