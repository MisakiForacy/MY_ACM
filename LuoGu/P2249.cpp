#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,l,r,mid;
    cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i ++)cin >> a[i];
    while (m --){
        cin >> x;
        l = 0, r = n;
        while (l <= r){
            mid = (l+r) / 2;
            if (a[mid]>=x) r = mid - 1;
            else l = mid + 1;
        }
        if(a[l]==x)cout << l+1 << " ";
        else cout << -1 << " ";
    }
}