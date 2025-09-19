#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n),ans(n),b;
    for (int i = 0;i < n;i ++){
        cin >> a[i];
    }
    b = a;
    sort(all(b));
    for (int i = 0;i < n;i ++){
        ans[i] = lower_bound(all(b),a[i]) - b.begin();
    }
    for (int i = 1;i <= k;i ++){
        int x,y;
        cin >> x >> y;
        x --, y --;
        if (a[x] > a[y]){
            ans[x] --;
        } else if (a[y] > a[x]){
            ans[y] --;
        }
    }
    for (int i = 0;i < n;i ++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}