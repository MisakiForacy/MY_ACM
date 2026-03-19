#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 cnt,i,j,n,idx;
vector<i64>arr;
int main(){
    cin >> n;
    arr.resize(n+1);
    for(i=1;i<=n;i++)cin >> arr[i];
    for(i=1;i<=n;i++){
        if(arr[i] != i){
            for(j=i+1;j<=n;j++){
                if(arr[j] == i){
                    idx = j;
                    break;
                }
            }
            swap(arr[i],arr[idx]);
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}