#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u_i64;
i64 n,b,i,idx;
static vector<i64>h;
static inline bool cmp(i64 &a,i64 &b){
    return a > b;
}
int main(){
    cin >> n >> b;
    h.resize(n);
    for(i=0;i<n;i++)cin >> h[i];
    sort(h.begin(),h.end(),cmp);
    idx = 0;
    while(b>0){
        b -= h[idx];
        idx++;
    }
    cout << idx << endl;
    return 0;
}