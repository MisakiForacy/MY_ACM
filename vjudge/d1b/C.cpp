#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,t=0;
    while (cin >> n){
        t ++;
        ll mx = 0;
        vector<int>ar(n);
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        for (int lo=0;lo<n;lo++){
            for (int hi=lo;hi<n;hi++){
                ll mtp = ar[lo];
                for (int k=lo+1;k<=hi;k++){
                    mtp *= ar[k];
                }
                mx = max(mx,mtp);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",t,mx);
    }
}