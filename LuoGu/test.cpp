#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
int n;
int a[N], b[N];
bool check(int x){
    for (int i=0;i<x;i++) b[i] = 0;
    for (int i=0;i<n;i++){
        if (b[a[i]%x]){
            return 0;
        }
        b[a[i]%x] ++;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = n;
    while (!check(ans)){
        ans ++;
    }
    cout << ans << '\n';
}