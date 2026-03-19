#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        vector<int> a(s.length()+1,0);
        for (int i=0;i<s.length();i++){
            a[i+1] = s[i] == '1';
        }
        int cnt = 0;
        int n = s.length();
        for (int i=1;i<=n-3;i++){
            if (a[i] && a[i+1] && !a[i+2] && !a[i+3]){
                cnt ++;
            }
        }
        int q,id,v;
        cin >> q;
        for (int i=0;i<q;i++){
            cin >> id >> v;
            if (a[id] == v){
                cout << (cnt?"YES\n":"NO\n");
            } else{
                if (v == 1){
                    if (id >= 4 && a[id-3] && a[id-2] && !a[id-1] && !a[id]){
                        cnt --;
                    } else if (id >= 3 && id <= n-1 && a[id-2] && a[id-1] && !a[id] && !a[id+1]){
                        cnt --;
                    }
                    a[id] = 1;
                    if (id <= n-3 && a[id] && a[id+1] && !a[id+2] && !a[id+3]){
                        cnt ++;
                    } else if (id >= 2 && id <= n-2 && a[id-1] && a[id] && !a[id+1] && !a[id+2]){
                        cnt ++;
                    }
                } else{
                    if (id <= n-3 && a[id] && a[id+1] && !a[id+2] && !a[id+3]){
                        cnt --;
                    } else if (id >= 2 && id <= n-2 && a[id-1] && a[id] && !a[id+1] && !a[id+2]){
                        cnt --;
                    }
                    a[id] = 0;
                    if (id >= 4 && a[id-3] && a[id-2] && !a[id-1] && !a[id]){
                        cnt ++;
                    } else if (id >= 3 && id <= n-1 && a[id-2] && a[id-1] && !a[id] && !a[id+1]){
                        cnt ++;
                    }
                }
                cout << (cnt?"YES\n":"NO\n");
            }
        }
    }
}