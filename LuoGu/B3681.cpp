#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll u[N],a[N];
int main(){
    int n;
    cin >> n;    
    for (int i=2;i<=n;i++) cin >> u[i];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=n;i>=2;i--){
        a[u[i]] += a[i];
    }
    for (int i=1;i<=n;i++){
        cout << a[i] << " \n"[i==n];
    }
}