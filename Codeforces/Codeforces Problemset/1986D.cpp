#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        if (n==2){
            cout << (s[0]-'0')*10 + (s[1]-'0') << '\n';
        } else{
            int mi = inf,idx;
            if (n==3 && s[1]=='0'){
                idx = 1;
            }
            for (int i=0;i<n-1;i++){
                if ((s[i]-'0')<mi && s[i]!='0' && s[i+1]!='0'){
                    mi = (s[i]-'0');
                    idx = i;
                } else if ((s[i]-'0')==mi && s[i+1]!='0' && s[i+1]!='1'){
                    idx = i;
                }
            }
            vector<int>a;
            for (int i=0;i<n;i++){
                if (i == idx){
                    int nn = (s[i]-'0')*10 + (s[++i]-'0');
                    a.push_back(nn);
                } else{
                    int nn = (s[i]-'0');
                    a.push_back(nn);
                }
            }
            int ans = 0,len = a.size();
            for (int i=0;i<len;i++){
                if (a[i]==0){
                    cout << 0 << '\n';
                    goto l;
                } else if (a[i]==1){
                    continue;
                } else{
                    ans += a[i];
                }
            }
            if (ans == 0){
                ans = 1;
            }
            cout << ans << '\n';
        }
        l:;
    }
}
