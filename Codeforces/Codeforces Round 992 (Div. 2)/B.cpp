#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	int T = 1;
	cin >> T;
	while (T--){
		int n,k;
		cin >> n >> k;
		vector<int> a(n+1,0);
		for (int i=1;i<=n;i++) cin >> a[i];
		int ok = 1;
		for (int i=1;i<=n;i++){
			ok = 1;
			for (int j=1;j<=n;j++){
				if (i != j && abs(a[i]-a[j])%k==0){
					ok = 0;
					break;
				}
			}
			if (ok){
				cout << "Yes\n";
				cout << i << '\n';
				break;
			}
		}
		if (!ok){
			cout << "No\n"; 
		}
	}
}