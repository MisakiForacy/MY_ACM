#include <bits/stdc++.h>
#define N (i64)(2e5+5)
using namespace std;
typedef long long i64;
i64 n,c,i,j,cnt,arr[N];
int main(){
    cin >> n >> c;
    for(i = 0; i < n; i ++)cin >> arr[i];
    sort(arr, arr + n);
    for(i = 0; i < n; i ++){
        cnt += (upper_bound(arr,arr + n,arr[i] + c) - lower_bound(arr,arr + n,arr[i] + c));
    }
    cout << cnt << endl;
    return 0;
}