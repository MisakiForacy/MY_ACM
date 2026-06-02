#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,hh=0,tt=0;
	cin>>n;
	vector<int> q(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==1){
			int x;
			cin>>x;
			q[tt++]=x;
		}else if(a==2){
			if(tt==hh){
                cout<<"ERR_CANNOT_POP"<<endl;
			}else{
				hh++;
			}
		}else if(a==3){
			if(tt==hh){
				cout<<"ERR_CANNOT_QUERY"<<endl;
			}else{
			    cout<<q[hh]<<endl;
			}
		}else if(a==4){
			cout<<(tt-hh)<<endl;
		}
	}
}