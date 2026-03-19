#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll n,ll m){
    if (n*n*n<m){
        return 1;
    }
    return 0;
}
int main(){
    ll n;
    cin >> n;
    ll lo = 1, hi = 1e5;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        if (check(mid,n)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (lo*lo*lo>n){
        lo --;
    }
    cout << lo << '\n';
}