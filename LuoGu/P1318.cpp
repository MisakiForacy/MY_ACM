#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef double llf;
i64 n,i,j,l,r,t,tt,h,ll,cnt;
vector<i64>arr;
int main(){
    cin >> n;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]>h)h=arr[i];
    }
    for(i=1;i<=h;i++){
        ll = 1;
        cnt = 0;
        for(j=1;j<n;j++){
            if(arr[j]>=i&&ll)l = j,ll = 0;
            if(arr[j]>=i)r = j,cnt++;
        }
        t = r - l + 1 - cnt;
        tt += t;
    }
    cout << tt << endl;
}