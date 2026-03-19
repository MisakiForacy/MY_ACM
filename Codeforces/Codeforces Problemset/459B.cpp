#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,mi,ma,datle,cnt;
    cin >> n;
    vector<int>ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    datle = ar[n-1] - ar[0];
    mi = ma = 0;
    for (int i=0;i<n;i++){
        if (ar[i]==ar[0]){
            mi ++;
        } else if (ar[i]==ar[n-1]){
            ma ++;
        }
    }
    if (ar[0]==ar[n-1]){
        cnt = 0;
        for (int i=1;i<mi;i++){
            cnt += i;
        }
    } else{
        cnt = mi * ma;
    }
    cout << datle << " " << cnt << '\n';
}