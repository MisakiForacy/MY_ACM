#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
const int N = 1e6+10;
const int mod = 998244353;
int a[N],b[N];

void solve(){
	int n,k;cin>>n>>k;
	int m;
	int ans = 0;
	rep(i,1,n) {
		cin>>a[i];
		ans+=a[i]/k;
		b[i] = a[i]%k;
		b[i] = k-b[i];
	}
	cin>>m;
	
	sort(b+1,b+1+n);
	rep(i,1,n){
		if(m<=0) break;
		if(m<b[i]) break;
		m-=b[i];ans++;
	}
	ans+=m/k;
	//cout<<"答案：";
	cout<<ans<<endl;
}

signed main(){
	
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}