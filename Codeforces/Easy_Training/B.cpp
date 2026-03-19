#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 t,n,ans;
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin >> arr[i];
        arr[min_element(arr.begin(),arr.end())-arr.begin()]++;
        ans = arr[0];
        for(int i=1;i<n;i++)ans *= arr[i];
        printf("%lld\n",ans);
    }
    return 0;
}