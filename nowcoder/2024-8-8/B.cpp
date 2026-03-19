#include <bits/stdc++.h>
using namespace std;
int xnor(int a,int b,int m){
    int ans = 0;
    for (int k=m-1;k>=0;k--){
        ans += (((a>>k)&1)==((b>>k)&1))*pow(2,k);
    }
    return ans;
}
int main(){
    int n,m,mx = 0;
    cin >> n >> m;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i=1;i<n;i++){
        mx = max(mx,xnor(a[i],a[i-1],m));
    }
    cout << mx << '\n';
}