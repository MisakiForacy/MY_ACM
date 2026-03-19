#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u_i64;
i64 n,i,j,cnt;
vector<i64>a;
int main(){
    cin >> n;
    a.resize(n);
    cnt = 0;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if(a[j] < a[j-1]){
                cnt++;
                swap(a[j],a[j-1]);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}