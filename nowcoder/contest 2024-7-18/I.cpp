#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ar;
vector<ll>lo,hi,c;
void f(int n){
    for (int i=lo[n];i<=hi[n];i++){
        if (c[i] > c[n]){
            f(i);
        }
    }
    vector<int>llo(n+1);
    for (int i=0;i<lo[n];i++){
        llo[ar[i]] ++;
    }
    for (int i=hi[n]+1;i<=n;i++){
        if (llo[ar[i]]){
            c[ar[i]] -= (hi[ar[i]]-lo[ar[i]]+1)*ar[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ar.resize(2*n+1);
    lo.resize(n+1,0);
    hi.resize(n+1,0);
    c.resize(n+1);
    for (int i=0;i<2*n;i++){
        cin >> ar[i];
        if (lo[ar[i]]){
            hi[ar[i]] = i;
        } else{
            lo[ar[i]] = i;
        }
    }
    for (int i=1;i<=n;i++){
        c[i] = (hi[i]-lo[i]+1) * i;
    }
    for (int i=n;i>=1;i--){
        f(i);
    }
}