#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long i64;
typedef double llf;
i64 maxn = -INF;
i64 i,j,m,n,res;
vector<i64>a;
int main(){
    cin >> n;
    a.resize(n);
    res = 0;
    for(i=0;i<n;i++){
        cin >> a[i];
        if(a[i] > maxn) maxn = a[i];
    }
    for(i=0;i<n;i++){
        if(a[i] != maxn)res += a[i];
    }
    cout << res << endl;
    return 0;
}