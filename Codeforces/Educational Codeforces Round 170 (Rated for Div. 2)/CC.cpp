#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[200000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	ll t,n,k,a;
	cin>>t;
	while(t--){
		map<int,int>mp;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			mp[a]++;
		}
		int cnt=0;
		for(auto x : mp){
			b[cnt]=x.first;
			cnt++;
		}
		int mx=0;
		int mn=0;
		int f=0,ff=1;
		for(int i=0;i<cnt;i++){
			if(f){
				if(ff){
					i+=k-1;
					ff=0;	
				}
				if(b[i]-b[i-1]==1) mn=mn-mp[b[i-k]]+mp[b[i]];
				else{
					f=0;
					i--;
				}
			}
			else{
				mn=mp[b[i]];
				int cnt=1;
				while(cnt<k){
					if(mp[b[i]+cnt]!=0){
						f=1;
						mn+=mp[b[i]+cnt];
						cnt++;
					} else{
						f=0;
						i += cnt-1;
						break;
					}
				}
				if(f) ff=1;
			}
			mx=max(mx,mn);
		}
		cout<<mx<<'\n';
	}
}