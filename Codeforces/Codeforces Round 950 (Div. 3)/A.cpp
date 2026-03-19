#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int alpha[200];
int main(){
    ll T,n,m,cnt;
    string s;
    cin >> T;
    while (T --){
        memset(alpha,0,sizeof(alpha));
        cin >> n >> m >> s;
        cnt = 0;
        for (int i=0;i<n;i++){
            alpha[s[i]] += 1;
        }
        for (int i=65;i<=71;i++){
            if (m - alpha[i] > 0)cnt += m - alpha[i];
        }
        cout << cnt << '\n';
    }
}