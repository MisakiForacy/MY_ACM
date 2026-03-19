#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define int long long
#define rep(i,a,b) for(int i = a;i<=b;i++)
int a[N],r[N],w[N];
void solve(){
	int n,m;cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	
	int sum = 0;
	int day = -1;
	priority_queue<int,vector<int>,greater<int> > h;
	rep(i,1,m) {
		cin>>r[i]>>w[i];
		sum+=w[i];
		if(day==-1) day = r[i];
		else day = min(day,r[i]);
	}
	
	
	rep(i,1,day){
		h.push(a[i]);
	}
	
	//cout<<"ans:"; 
	int f = 0;
	while(h.size()){
		if(f) cout<<" ";
		sum-=h.top();
		cout<<-sum;
		h.pop();
		if(!f){
			f = 1;
			rep(i,day+1,n){
				h.push(a[i]);
			}
		}
	}
	cout<<endl;
	
}

signed main(){
	int t = 1;
	cin>>t;
	while(t--) solve();
}
 
