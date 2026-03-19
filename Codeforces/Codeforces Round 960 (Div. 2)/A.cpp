#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[100];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,mx = 0,cnt = 0,f=0;
        cin >> n;
        vector<ll>ar(n);
        memset(num,0,sizeof(num));
        for (int i=0;i<n;i++){
            cin >> ar[i];
            num[ar[i]]++;
        }
        for (int i=0;i<=50;i++){
            if (num[i]&1) f = 1;
        }
        cout << (f?"YES\n":"NO\n");
    }
}