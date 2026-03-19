#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char c;
int main()
{
    cin>>n;
    ll a,b,x,y;
    scanf("%lld/%lld",&a,&b);
    for(int i=1;i<n;i++)
    {
        scanf("%lld/%lld",&x,&y);
        int bb=b,yy=y;
        if(b<y)
        {
            int temp=b;
            bb=y;
            yy=temp;
        }
        ll mu=b*y/__gcd(bb,yy);
        ll zi=a*(mu/b)+x*(mu/y);
        a=zi,b=mu;
    }
    ll k = __gcd(a,b);
    a/=k,b/=k;
    ll q=a/b;
    ll r=a%b;
    if(r==0 && q==0) cout<<"0"<<endl;
    else if(r==0 && q!=0) cout<<q<<endl;
    else if(r!=0 && q!=0) cout<<q<<" "<<r<<"/"<<b<<endl;
    else if(r!=0 && q==0) cout<<r<<"/"<<b<<endl;
	return 0;
} 
