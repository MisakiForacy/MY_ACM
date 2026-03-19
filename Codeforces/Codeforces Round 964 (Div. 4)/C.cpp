#include <bits/stdc++.h>
using namespace std;
struct haha{
    int st,ed;
};
bool cmp(haha a,haha b){
    if (a.st != b.st) return a.st < b.st;
    return a.ed < b.ed;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,s,m;
        cin >> n >> s >> m;
        vector<haha>t(n+2);
        t[0].st = 0, t[0].ed = 0;
        for (int i=0;i<n;i++){
            cin >> t[i].st >> t[i].ed;
        }
        t[n+1].st = m, t[n+1].ed = m;
        sort(t.begin(),t.end(),cmp);
        int ok = 0;
        for (int i=1;i<=n+1;i++){
            if (t[i].st-t[i-1].ed>=s){
                ok = 1;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}