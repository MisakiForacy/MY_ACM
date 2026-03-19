#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    struct node{
        string n,s;
        bool operator < (const node&that) const {
            if (s != that.s){
                return s < that.s;
            }
            return n < that.n;
        }
    };
    int T,TT;
    cin >> T;
    TT = T;
    while (T--){
        if (TT-T>1){
            cout << '\n';
        }
        cout << "Case " << TT-T << ":\n";
        int n;
        cin >> n;
        map<string,string> mp;
        vector<node> lst(n);
        vector<string> sit(200,"");
        for (int i=0;i<n;i++){
            cin >> lst[i].n >> lst[i].s;
            mp[lst[i].n] = lst[i].s;
        }
        sort(lst.begin(),lst.end());
        for (int i=0;i<n;i++){
            // cout << lst[i].n << '\n';
            sit[i+1] = lst[i].n;
        }
        int m,x;
        cin >> m;
        vector<int> bad(200,0);
        for (int i=0;i<m;i++){
            cin >> x;
            bad[x] = 1;
        }
        int newsit = n;
        for (int i=1;i<=n;i++){
            if (bad[i]){
                while (bad[++newsit]);
                sit[newsit] = sit[i];
                sit[i] = "";
                // newsit ++;
            }
        }
        int nn = 0;
        int idx = 1;
        while (nn < n){
            while (sit[idx]=="") idx ++;
            // cout << idx << ' ' << sit[idx] << '\n';
            printf("%03d:",idx);
            cout << sit[idx] << ' ' << mp[sit[idx]] << '\n';
            nn ++;
            idx ++;
        }
        // cout << '\n';
    }
}