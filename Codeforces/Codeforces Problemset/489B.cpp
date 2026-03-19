#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,p1,p2,pp2,cnt=0;
    cin >> n;
    vector<ll>a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> m;
    vector<ll>b(m+1);
    for (int i=1;i<=m;i++){
        cin >> b[i];
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    p1 = p2 = pp2 = 1;
    for (p1 = 1;p1<=n;p1++){
        while (p2<=m&&abs(a[p1]-b[p2])>1){
            p2 ++;
        }
        if (p2<=m){
            p2 ++;
            pp2 = p2;
            cnt ++;
        } else{
            p2 = pp2;
        }
    }
    cout << cnt << '\n';
}