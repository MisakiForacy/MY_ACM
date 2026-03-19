#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
const int mod = 998244353;
int f[N] = {0,1};
int ans[N];
int main(){
	vector<int>a;
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		for (int j=1;i*j<=n;j++){
			(f[j*i+1] += f[i]) %= mod;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j+=i){
			(ans[j] += f[i]) %= mod;
		}
	}
	for (int i=1;i<=n;i++) cout << ans[i] << " \n"[i==n];
}
