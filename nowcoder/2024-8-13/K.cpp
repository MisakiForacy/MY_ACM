#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f;

vector<ll>a;
ll ans = inf;

int check(int mid,int k){
    int cnt = 0;
    for (int i=mid+1;i<a.size();i++){
        int t = a[i];
        while (t > a[mid]){
            t /= k;
            cnt ++;
        }
    }
    if (cnt + a[mid] <= ans){
        ans = cnt + a[mid];
        return 1;
    }
    return 0;
}

int main(){
    int n,k;
    cin >> n >> k;
    a.resize(n);
    ll lo = 0,hi = n;
    for (int i=0;i<n;i++) cin >> a[i];
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (check(mid,k)) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ans << '\n';
}