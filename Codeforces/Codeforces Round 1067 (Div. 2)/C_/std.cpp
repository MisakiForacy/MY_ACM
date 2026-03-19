#include<bits/stdc++.h>
using namespace std;

std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
typedef unsigned long long ll;
#define int long long 

void solve(){
	int n,k;cin>>n>>k;
	vector<int> a(n+1),b(n+1);
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>b[i];
	}
	vector<vector<int>> sttmx(n+2,vector<int> (24,0));
	vector<vector<int>> sttmn(n+2,vector<int> (24,0));

	for(int i = 1;i<=n;i++) sttmx[i][0] = a[i]+sttmx[i-1][0];
	for(int j = 1;j<=23;j++)
	{
		for(int i = 1;i+(1<<j)-1<=n;i++)
		{
			sttmx[i][j] = max(sttmx[i][j-1],sttmx[i+(1<<(j-1))][j-1]);
		}
	}
	auto qmax = [&](int l,int r)->int{
		int kk = log2(r-l+1);
		return max(sttmx[l][kk],sttmx[r-(1<<kk)+1][kk]);
	};

	for(int i = 1;i<=n;i++) sttmn[i][0] = a[i]+sttmn[i-1][0];
	for(int j = 1;j<=23;j++)
	{
		for(int i = 1;i+(1<<j)-1<=n;i++)
		{
			sttmn[i][j] = min(sttmn[i][j-1],sttmn[i+(1<<(j-1))][j-1]);
		}
	}
	auto qmin = [&](int l,int r)->int{
		int kk = log2(r-l+1);
		return min({0LL,sttmn[l][kk],sttmn[r-(1<<kk)+1][kk]});
	};
	int ans = -1e18;
	if(k&1){
		for(int i = 1;i<=n;i++){
			int zuo = 0,you = 0;
			if(i>1) zuo = max(sttmn[i-1][0]-qmin(1, i-1),0LL);
			if(i<n) you = max(0LL,qmax(i+1,n)-sttmx[i][0]);
			// cout<<zuo<<" "<<you<<"\n";
			ans = max(ans,a[i]+zuo+you+b[i]);
		}
	}else{
		for(int i = 1;i<=n;i++){
			int zuo = 0,you = 0;
			if(i>1) zuo = max(sttmn[i-1][0]-qmin(1, i-1),0LL);
			if(i<n) you = max(0LL,qmax(i+1,n)-sttmx[i][0]);
			// cout<<zuo<<" "<<you<<"\n";

			ans = max(ans,a[i]+zuo+you);
		}
	}
	// cout<<qmin(1,1)<<"---\n";
	cout<<ans<<"\n";
	


}

signed main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	std::cin>>T;
	while(T--) solve();
	return 0;
}