#include<bits/stdc++.h>;
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i = a;i<=b;i++)
const int N = 1e6+10;
int n;
vector<int> v;
int a[N];//最后结果 
map<int,int> b;
//int ans[N];
bool check(){
	rep(i,1,n){
		if(v[i-1]!=a[i]) return 0;
	}
	
	return 1;
}
void solve(){
	cin>>n;
	v.clear();b.clear();
	//int pans = 1;
	
	
	rep(i,1,n){
		int x;cin>>x;
		v.push_back(x);
	}
	rep(i,1,n) {
		int x;cin>>x;
		a[i] = x;
		b[x] = i;
	}
	//cout<<"答案：";
	while(!check()){
		int f = 1;//用来记录是用判断条件1还是2 
		int last = v.back();
		int index = b[last];
		// if(index==n) f = 2;
		// if(a[index+1]!=v[0] && a[index+1]!=v[1]) f = 2;
		
		if(f==1){
			if(a[index+1]==v[0]){
				cout<<1;
				v.push_back(v[0]);
				v.erase(v.begin());
			}
			else{
				cout<<2;
				v.push_back(v[1]);
				v.erase(v.begin()+1);
			}
		}
		else{
			//1 2
			//2 1
			if(b[v[0]]<=b[v[1]]){
				cout<<1;
				v.push_back(v[0]);
				v.erase(v.begin());
			}
			else{
				cout<<2;
				v.push_back(v[1]);
				v.erase(v.begin()+1);
			}
		}
		
	}
	cout<<'\n';
}

signed main(){
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}