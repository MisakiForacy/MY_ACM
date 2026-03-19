#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> nu,pre(n+1,0);
    for (int i=0;i<n;i++){
        int a,b,c,x;
        char o;
        scanf("%dx%c%d=%d",&a,&o,&b,&c);
        if (o == '+'){
            x = (c - b) / a;
        } else{
            x = (c + b) / a;
        }
        nu.push_back(x);
    }
    sort(nu.begin(),nu.end());
    nu.erase(unique(nu.begin(),nu.end()),nu.end());
    for (int i=0;i<q;i++){
        int lo,hi;
        cin >> lo >> hi;
        lo = lower_bound(nu.begin(),nu.end(),lo)-nu.begin();
        hi = upper_bound(nu.begin(),nu.end(),hi)-nu.begin();
        cout << hi - lo << '\n';
    }
}