#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],b[N],n;
vector<int> sn[N];
int tr[N];
int sz[N],lsn[N];
void ad(int x,int v){
	while(x<=n){
		tr[x]+=v;
		x+=x & -x;
	}
}
int su(int x){
	int sum=0;
	while(x){
		sum+=tr[x];
		x-=x & -x;
	}
	return sum;
}
void dfs1(int u,int fa){
	sz[u]=1;
	lsn[u]=0;
	int mxsz=0;
	for(int v=0;v<sn[u].size();v++){
		if(sn[u][v]==fa){
			continue;
		}
		dfs1(sn[u][v],u);
		sz[u]+=sz[sn[u][v]];
		if(sz[sn[u][v]]>mxsz){
			mxsz=sz[sn[u][v]];
			lsn[u]=sn[u][v];
		}
	}
}
void l(int u,int fa,int nu){
	ad(a[u],nu);
	for(int x=0;x<sn[u].size();x++){
		if(sn[u][x]!=fa){
			l(sn[u][x],u,nu);
		}
	}
}
int cnt[N];
void dfs2(int u,int fa,int bo){
	for(int x=0;x<sn[u].size();x++){
		if(sn[u][x]!=fa && sn[u][x]!=lsn[u]){
			dfs2(sn[u][x],u,0);
		}
	}
    // cout << u << ' ' << lsn[u] << '\n';
	if(lsn[u]){
		dfs2(lsn[u],u,1);
	}
	for(int v:sn[u]){
		if(v!=fa && v!=lsn[u]){
			l(v,u,1);
		}
	}
	ad(a[u],1);
	cnt[u]=su(n)-su(a[u]);
	// cout<<cnt<<'\n';
	if(!bo){
		l(u,fa,-1);
	}
}
int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	// ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		b[i]=a[i];
	} 
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	}
	for(int i=2;i<=n;i++){
        int f;
		cin>>f;
		sn[f].push_back(i);
	}
    // cout << "OK\n";
	dfs1(1,0);
	dfs2(1,0,1);
    for (int i = 1;i <= n;i ++) cout << cnt[i] << '\n';
	return 0;
}


