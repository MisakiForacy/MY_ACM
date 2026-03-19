#include<bits/stdc++.h>
using namespace std;

vector<int> ca(5e5+1,0);
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t = 1;
	cin>>t;
	for(;t>0;t--){
		int n;
		cin>>n;
		vector<int> alice(n);
		unordered_map<int,int> hs;
		vector<int> atwo,btwo,ans(n,0);
		deque<int> one;
		for(auto &i:alice){
			cin>>i;
			ca[i]++;
		}
		for(int i=1;i<=n;i++){
			if(ca[i]==2) atwo.emplace_back(i);
			else if(ca[i]==0) btwo.emplace_back(i);
		}
		for(auto &i:alice){
			if(ca[i]==1) one.emplace_back(i);
		}
		for(int i=0;i<atwo.size();i++) hs[atwo[i]]=btwo[i];
		for(int i=1;i<n;i++){
			if(hs[alice[i]]!=0) ans[i-1]=hs[alice[i]];
		}
		if(hs[alice[0]]!=0) one.push_front(hs[alice[0]]);
		for(int i=0;i<n;i++){
			if(ans[i]==0){
				ans[i]=one.front();
				one.pop_front();
			}
		}
		if(ca[alice[0]]==1) cout<<0<<"\n";
		else cout<<1<<"\n";
		for(auto &i:ans) cout<<i<<" ";
		cout<<"\n";
		for(int i=0;i<=n;i++) ca[i]=0;
	}
    return 0;
}
