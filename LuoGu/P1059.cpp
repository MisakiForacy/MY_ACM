#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,k,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    l = unique(a,a+n) - a;
    cout << l << endl;
    for(i=0;i<l;i++)cout << a[i] << " ";
    return 0;
}