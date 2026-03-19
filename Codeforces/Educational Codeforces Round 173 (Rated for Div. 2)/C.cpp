#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        set<LL> ans;
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0);
        int id = 1;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            if (a[i] != 1 && a[i] != -1) id = i;
        }
        LL mx, mi, smx1, smi1;
        mx = smx1 = -1e12, mi = smi1 = 1e12;
        mx = mi = 0;
        for (int i=0;i<id;i++){
            mx = max(mx,pre[i]);
            mi = min(mi,pre[i]);
            smx1 = max(smx1,pre[i] - mi);
            smi1 = min(smi1,pre[i] - mx);
        }
        for (LL i=smi1;i<=smx1;i++) ans.insert(i);
        LL smx2,smi2;
        mx = smx2 = -1e12, mi = smi2 = 1e12;
        mx = mi = pre[id];
        for (int i=id;i<=n;i++){
            mx = max(mx,pre[i]);
            mi = min(mi,pre[i]);
            smx2 = max(smx2,pre[i] - mi);
            smi2 = min(smi2,pre[i] - mx);
        }
        for (LL i=smi2;i<=smx2;i++) ans.insert(i);
        // mi = min(smi1,smi2);
        // mx = max(smx1,smx2);
        mi = smi1 + smi2;
        mx = smx1 + smx2;
        for (LL i=mi;i<=mx;i++) ans.insert(i+a[id]);
        cout << ans.size() << '\n';
        for (auto x:ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}