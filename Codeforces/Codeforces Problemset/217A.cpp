#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << '\n'
#define N 1005
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f;
ll Set1[N],Set2[N];
ll num1[N],num2[N];
void merge(ll a,ll b,ll Set[N]){
    Set[a] = b;
}
ll findx(ll x,ll Set[N]){
    if (findx(x,Set) != x){
        Set[x] = findx(x,Set);
    }
    return Set[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    ll n,cnt1,cnt2;
    cnt1=cnt2=0;
    cin >> n;
    vector<ll>x(n);
    vector<ll>y(n);
    for (int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        Set1[x[i]] = y[i];
        Set2[y[i]] = x[i];
    }
    for (int i=0;i<n;i++){
        findx(x[i],Set1);
        findx(y[i],Set2);
    }
    for (int i=0;i<n;i++){
        if (!num1[Set1[x[i]]]){
            cnt1 ++;
            num1[Set1[x[i]]]++;
        }
        if (!num2[Set2[y[i]]]){
            cnt2 ++;
            num2[Set2[y[i]]]++;
        }
    }
    cout << min(cnt1,cnt2)-1 << '\n';
}