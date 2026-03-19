#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef double llf;
i64 n,i,l,r,x,y,cnt;
int main(){
    cin >> n;
    cin >> x;
    for(i=1;i<n;i++){
        cin >> y;
        if(y<x)l=1;
        if(x<y&&l)l=0,cnt++;
        x = y;
    }
    cout << cnt << endl;
    return 0;
}