#include <bits/stdc++.h>
#define inf (i64)(1e15)
using namespace std;
typedef long long i64;
i64 n,i,j,x;
i64 maxn = -inf, minn;
int main(){
    cin >> n;
    cin >> minn;
    for(i=2;i<=n;i++){
        cin >> x;
        if(x - minn > maxn)maxn = x - minn;
        if(x < minn)minn = x;
    }
    cout << maxn;
    return 0;
}