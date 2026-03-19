#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l=0,r=0,ans=1;
    cin >> n;
    vector<int>a(n+1,0),diff(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        diff[i] = a[i] - a[i-1];
        if (!l&&diff[i]<0){
            l = i-1;
        }
        if (l&&!r&&diff[i]>0){
            r = i-1;
        }
        if (r&&diff[i]<0){
            ans = 0;
        }
    }
    if (l&&!r){
        r = n;
    }
    if (l&&r){
        if (r!=n&&(a[r]<a[l-1]||a[l]>a[r+1])){
            ans = 0;
        } else if(r==n&&a[r]<a[l-1]){
            ans = 0;
        }
    }
    if (ans){
        cout << "yes\n";
        if (l&&r){
            cout << l << " " << r << '\n';
        } else{
            cout << 1 << " " << 1 << '\n';
        }
    } else{
        cout << "no\n";
    }
}