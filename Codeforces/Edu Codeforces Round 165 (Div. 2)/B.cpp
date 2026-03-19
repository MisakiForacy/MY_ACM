#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string ss;
ll res,t,i,k,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        res = 0;
        k = 0;
        cin >> ss;
        n = ss.size();
        for(i=0;i<n;i++){
            k+=(ss[i]=='1');
        }
        if(k==n || k==0){
            cout << res << endl;
        }
        else{
            for(i=n-1;i>-1;i--){
                if(ss[i]=='1'){
                    k--;                    
                }
                else{
                    res += k+1;
                }
                if(!k)break;
            }
            cout << res << endl;
        }
    }
}