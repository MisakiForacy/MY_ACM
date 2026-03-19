#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    LL tot = 0;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=1;i<n;i++){
        tot += max(a[i-1],a[i]);
    }
    cout << tot << '\n';
}