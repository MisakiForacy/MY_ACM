#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    LL n1 = 0, n2 = 0;
    for (int i=0;i<n/2;i++){
        n1 += a[i];
    }
    for (int i=n/2;i<n;i++){
        n2 += a[i];
    }
    cout << n2 - n1 << '\n';
}