#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Check(vector<ll>a1,vector<ll>a2,vector<ll>a3,ll &l1,ll &r1,ll &l2,ll &r2,ll &l3,ll &r3,ll ave,ll n){
    ll hi,s1,s2;
    l1 = 1, r1 = l1, hi = n-2;
    while (r1 <= hi){
        ll mid = (r1+hi) / 2;
        s1 = a1[mid] - a1[l1-1];
        if (s1 >= ave) hi --;
        else r1 ++;
    }
    l2 = r1 + 1, r2 = l2, hi = n-1;
    while (r2 <= hi){
        ll mid = (r2+hi) / 2;
        s2 = a2[mid] - a2[l2-1];
        if (s2 >= ave) hi --;
        else r2 ++;
    }
    l3 = r2 + 1, r3 = n;
    if (a1[r1]-a1[l1-1]>=ave && a2[r2]-a2[l2-1]>=ave && a3[r3]-a3[l3-1]>=ave){
        return 1;
    }
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,tot,ave,la,ra,lb,rb,lc,rc;
        cin >> n;
        tot = 0;
        vector<ll>a(n+1),b(n+1),c(n+1),pa(n+1,0),pb(n+1,0),pc(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            tot += a[i];
            pa[i] = pa[i-1] + a[i];
        }
        for (int i=1;i<=n;i++) cin >> b[i], pb[i] = pb[i-1] + b[i];
        for (int i=1;i<=n;i++) cin >> c[i], pc[i] = pc[i-1] + c[i];
        ave = tot / 3 + (tot%3?1:0);
        if (Check(pa,pb,pc,la,ra,lb,rb,lc,rc,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        if (Check(pa,pc,pb,la,ra,lc,rc,lb,rb,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        if (Check(pb,pa,pc,lb,rb,la,ra,lc,rc,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        if (Check(pb,pc,pa,lb,rb,lc,rc,la,ra,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        if (Check(pc,pa,pb,lc,rc,la,ra,lb,rb,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        if (Check(pc,pb,pa,lc,rc,lb,rb,la,ra,ave,n)){
            printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);
            continue;
        }
        cout << -1 << '\n';
        continue;
    }
}

// next_permutation