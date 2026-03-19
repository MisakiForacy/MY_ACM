#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k,i;
    cin >> n >> k;
    int a[n];
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    cout << a[k] << endl;
    return 0;
}