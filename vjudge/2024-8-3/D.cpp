#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    cin >> a[0];
    for (int i=1;i<n;i++){
        cin >> a[i];
        cout << a[i] * a[i-1] << " \n"[i==n-1];
    }
}