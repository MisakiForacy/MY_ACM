#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	ll a[10]={1,5,10,25,50},dp[10005];
	dp[0]=1;
	for (int i=0;i<=4;i++){
		for (int j=a[i];j<=10000;j++){
			dp[j]=dp[j]+dp[j-a[i]];
		}
	}
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}