#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        vector<int>pre(n+1,0);
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + (s[i-1]-'0');
        }
        int mi = inf;
        int idx = 0;
        int le,ri;
        for (int i=0;i<=n;i++){    
            le = pre[i] - pre[0];
            ri = pre[n] - pre[i];
            if ((i-le>=ceil(i*0.5)) && (ri>=ceil((n-i)*0.5))){
                if (abs(1.0*n/2-i)<mi){
                    idx = i;
                    mi = abs(1.0*n/2-i);
                    // cout << i << ' ' << abs(n/2-i) << ' ' << le << ' ' << ri << ' ' << idx << '\n';
                }
            }
        }
        cout << idx << '\n';
    }
}