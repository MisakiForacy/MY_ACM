#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T,n,m,ma,cnt,y,x,f;
    string s;
    cin >> T;
    while (T --){
        ma = 0;
        cin >> n >> m;
        for (int i=0;i<n;i++){
            cnt = 0;
            cin >> s;
            f = -1;
            for (int j=0;j<m;j++){
                if (s[j]=='#'){
                    cnt ++;
                    if (f==-1){
                        f = j;
                    }
                }
            }
            // debug(cnt);
            if (cnt > ma){
                ma = cnt;
                y = i;
                x = f + cnt/2;
            }
        }
        cout << y+1 << " " << x+1 << '\n';
    }
}