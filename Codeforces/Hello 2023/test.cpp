#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,hh=0,tt=0;
	cin>>n;
	vector<int> q(n);
	bool first=true;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==1){
			int x;
			cin>>x;
			q[tt++]=x;
		}else if(a==2){
			if(tt==hh){
			if(!first) cout<<endl;
			cout<<" ERR_CANNOT_POP";
			first=false;
			}else{
				hh++;
			}
		}else if(a==3){
			if(tt==hh){
				if(!first) cout<<endl;
				cout<<"ERR_CANNOT_QUERY";	
			    first=false;
			}else{
				if(!first) cout<<endl;
			    cout<<q[hh];
			    first=false;
			}
		}else if(a==4){
			if(!first) cout<<endl;
			cout<<(tt-hh);
			first=false;
		}
	}

}