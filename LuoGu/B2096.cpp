#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n,x,i,j,f,cnt;
vector<i64>arr;
vector<i64>num(100000,0);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    arr.resize(n);
    cin >> arr[0];
    f = arr[0];
    num[arr[0]]++;
    for(i=1;i<n;i++){
        cin >> arr[i];
        num[arr[i]]++;
        if(arr[i] > f)f = arr[i];
    }
    for(i=0;i<=f;i++){
        cout << num[i] << endl;
    }
    return 0;
}