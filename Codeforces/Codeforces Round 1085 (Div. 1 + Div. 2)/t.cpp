#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30;
int dp[N];
int n;
int a[N][N];
int p[N];
int pre[N];
int k;
void print(int zhong){
	if (pre[zhong] == 0){
		cout << zhong <<" ";
		return;
	}
	print(pre[zhong]);
	
	cout << zhong <<" ";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> p[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = i+1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= n;i++){
		dp[i] = p[i];
		for (int j = 1;j <= i;j++){
			if (a[j][i] == 1){
				if (dp[i] < dp[j]+p[i]){
					dp[i] = dp[j]+p[i];
					pre[i] = j;
				}
			}
		}
	}
	int ans = 0;
	int zhong = 0;
	for (int i = 1;i <= n;i++){
		if (ans < dp[i]){
			ans = dp[i];
			zhong = i;
		}
	}
	print(zhong);
	cout << "\n";
	cout << ans <<endl;
	return 0;
}