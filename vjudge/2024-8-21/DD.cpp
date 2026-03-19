#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int prime[N+5];
int vit[N+5],vis[N+5];
int a,b,p,k,f=0;
int main(){
	cin>>a>>b>>p;
	int cnt=b-a+1;
	for(int j=2;j<=b;j++){
		if(!vit[j]&&j>=p){
			int cnt1=-1;
			f=0;
			for(int i=a;i<=b;){
				if(i%j==0){
					if(!vis[i]){
						cnt1++;
						vis[i]=1;
						vit[i]=1;
					}
					else f=1;
					i+=j;
				}
				else i++;
			}
			if(cnt1 !=-1){
				if(f) cnt=cnt-cnt1-1;
				else cnt=cnt-cnt1;
			}
		}
		else{
			for(int i=j;i<=b;i+=j){
				if(!vis[i]){
					vit[i]=1;
				}
			}
		}	
	}
	cout<<cnt;
	return 0;
}