#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    i64 n,m,x,idx,cnt=0;
    cin >> n >> m;
    idx = 1;
    for (int i=0;i<m;i++){
        cin >> x;
        if (x < idx) {
            cnt += n-idx+x;
            idx = x;
        } else {
            cnt += x-idx;
            idx = x;
        }
    }
    cout << cnt << '\n';
}