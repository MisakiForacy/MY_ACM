#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n,m,i,j,k,tot,res,tots;
vector<i64>s,l,t;
i64 f(i64 t);
int main(){
    cin >> m >> n;
    s.resize(m+1), l.resize(m+1), t.resize(m+1);
    for(i=1;i<=m;i++)cin >> s[i], tots += s[i];
    for(i=1;i<=m;i++)cin >> l[i], tot += s[i] + l[i];
    for(i=1;i<=m;i++){
        if(s[i])t[i] += tot;
        if(l[i])t[i] += tots;
    }
    while(n--){
        
    }
    for(i=1;i<=m;i++){
        res += t[i];
    }
    cout << res << endl;
    return 0;
}
