#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll toD(string s){
    ll n = 0;
    for (int i=0;i<int(s.length());i++){
        if (s[i]=='1'){
            n += pow(2,i);
        }
    }
    return n;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        bitset<64>a(n);
        vector<ll>ans;
        int k = a.count();
        string s = "";
        int kk = k;
        for (int i=0;i<64;i++){
            if (a[i]==1){
                s.push_back('1');
                kk --;
            } else{
                s.push_back('0');
            }
            if (!kk) break;
        }
        ans.push_back(toD(s));
        for (int i=1;i<=k;i++){
            int 
        }
        if (k == 1){
            cout << 1 << '\n' << n << '\n';
        } else{
            cout << k + 1 << '\n';
            for (int i=k;i>=0;i--){
                cout << ans[i] << " \n"[i==0];
            }
        }
    }
}