#include <iostream>
#include <vector>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
using namespace std;
typedef long long ll;
int main(){
    ll n,x,y,p,k;
    cin >> n >> x >> y >> p;
    vector<ll>a;
    vector<ll>tmp;
    vector<ll>ans(p,0);
    FOR(i,0,n,1){
        ll aa;cin >> aa;
        a.push_back(aa);tmp.push_back(aa);
    }
    FOR(i,0,p,1){
        FOR(j,0,n,1){
            a[j] = (a[j]*1ll*x+y)%p;
            if(a[j]==tmp[j])ans[i]++;
        }
    }
    ll m;cin >> m;
    while(--m+1){
        cin >> k;
        cout << ans[(k-1)%p] << endl;
    }
    return 0;
}
