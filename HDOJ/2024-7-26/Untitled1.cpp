#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long

const int N = 1e6+10;
struct Node{
	int index,val;
	string name;
	int rank;
}node[N];

bool cmp(Node e1,Node e2){
	return e1.val>e2.val;
}
bool cmp2(Node e1,Node e2){
	return e1.index<e2.index;
}

int c[N];
void solve(){
	int n,k;cin>>n>>k;
	int x = -1;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		if(x==-1) x = c[i];
		else x = min(x,c[i]);
	}
	for(int i = 1;i<=n;i++){
		node[i].index = i;
		cin>>node[i].val>>node[i].name;
		//cout<<"nb"<<endl;
	}
	sort(node+1,node+1+n,cmp);
	
	map<string,int> mp;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		string name;name+=node[i].name;
		mp[name]++;
		if(mp[name]<=x) cnt++;
		
		node[i].rank = cnt;
	}
	sort(node+1,node+1+n,cmp2);
	
	for(int i = 1;i<=n;i++){
		//cout<<"ans:";
		cout<<node[i].rank<<endl;
	}
	
}

signed main(){
	int T = 1;
	//cin >> T;
    while(T--){
	   	solve();
	}
}
