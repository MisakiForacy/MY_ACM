#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ldb=long double;
using ull=unsigned long long;
const long long inf=0x3f3f3f3f3f3f3f3f;
using i128=__int128;
const int mod=1000000007;
const long double eps=0.00000000001;

struct node{
    ll l,r;
    ll g;
}tree[1600010];
ll a[200010];
ll b[200010];
void build(ll s,ll t,ll p){
    if(s==t){
        tree[p].l=tree[p].r=s;
        tree[p].g=0;
        return;
    }
    ll mid=(s+t)>>1;
    build(s,mid,p<<1);
    build(mid+1,t,p<<1|1);
    tree[p].g=gcd(tree[p<<1].g,tree[p<<1|1].g);
    tree[p].l=tree[p<<1].l;
    tree[p].r=tree[p<<1|1].r;
}
void ddxg(ll k,ll v,ll s,ll t,ll p){
    if(s==t){
        tree[p].g=v;
        return;
    }
    ll mid=(s+t)>>1;
    if(k<=mid)ddxg(k,v,s,mid,p<<1);
    if(k>=mid+1) ddxg(k,v,mid+1,t,p<<1|1);
    tree[p].g=gcd(tree[p<<1].g,tree[p<<1|1].g);
    tree[p].l=tree[p<<1].l;
    tree[p].r=tree[p<<1|1].r;
}
node getans(ll l,ll r,ll s,ll t,ll p){
    if(l<=s&&r>=t){
        return tree[p];
    }
    else{
        node ans;
        ll mid=(s+t)>>1;
        if(r<=mid){
            ans=getans(l,r,s,mid,p<<1);
        }
        if(l>=mid+1){
            ans=getans(l,r,mid+1,t,p<<1|1);
        }
        if(l<=mid&&r>=mid+1){
            node x=getans(l,r,s,mid,p<<1);
            node y=getans(l,r,mid+1,t,p<<1|1);
            ans.g=gcd(llabs(x.g),llabs(y.g));
            ans.l=x.l,ans.r=y.r;
        }
        return ans;
    }
}

ll f(ll x){
    ll sum=0;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            if(i==x/i){
                sum++;
            }
            else sum+=2;
        }
    }
    return sum;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>a[i];
    build(1,n,1);
    for(ll i=2;i<=n;i++){
        if(a[i]<a[i-1]){
           ddxg(i-1,i-1,1,n,1);
        }
    }
    
    node ans=getans(1,n,1,n,1);
    printf("%lld\n",f(ans.g));

    while(q--){
        ll ps,v;
        cin>>ps>>v;
        if(ps==1){
            if(v<=a[ps+1]){
                ddxg(ps,0,1,n,1);
                a[ps]=v;
            }
            else if(v>a[ps+1]){
                ddxg(ps,ps,1,n,1);
                a[ps]=v;
            }
        }
        else if(ps==n){
            if(a[ps-1]<=v){
                ddxg(ps-1,0,1,n,1);
                a[ps]=v;
            }
            else if(a[ps-1]>v){
                ddxg(ps-1,ps-1,1,n,1);
                a[ps]=v;
            }
        }
        else{
            if(v<=a[ps+1]){
                ddxg(ps,0,1,n,1);
                a[ps]=v;
            }
            else if(v>a[ps+1]){
                ddxg(ps,ps,1,n,1);
                a[ps]=v;
            }
            if(a[ps-1]<=v){
                ddxg(ps-1,0,1,n,1);
                a[ps]=v;
            }
            else if(a[ps-1]>v){
                ddxg(ps-1,ps-1,1,n,1);
                a[ps]=v;
            }

        }
        ans=getans(1,n,1,n,1);
        printf("%lld\n",f(ans.g));
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}