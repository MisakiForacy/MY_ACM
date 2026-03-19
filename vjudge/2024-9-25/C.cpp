#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll a,b,c,x,cnt;
    bool operator < (const haha &that) const {
        if (cnt != that.cnt){
            return cnt > that.cnt;
        }
    }
};
int main(){
    ll n,m;
    ll ans = 0;
    cin >> n >> m;
    vector<haha> ar(n);
    priority_queue<haha> Q;
    for (int i=0;i<n;i++){
        cin >> ar[i].a >> ar[i].b >> ar[i].c;
        ans += ar[i].a + ar[i].b + ar[i].c;
        ll cnt = ar[i].a * 3 + ar[i].b;
        Q.push({ar[i].a,ar[i].b,ar[i].c,2,cnt});
    }
    for (int i=0;i<m-n;i++){
        auto [a,b,c,x,cnt] = Q.top();
        Q.pop();
        ans += cnt;
        cnt = a * ((x+1)*(x+1)-x*x)+b;
        x++;
        //  cout<<cnt<<endl;
        Q.push({a,b,c,x,cnt});
    }
    cout << ans << '\n';
}