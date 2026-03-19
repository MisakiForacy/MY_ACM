#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll a,b;
    bool operator < (const haha &that){
        return max(a,b) > max(that.a,that.b);
    }
};
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        vector<haha>mat(n);
        for (int i=0;i<n;i++){
            cin >> mat[i].a >> mat[i].b;
        }

    }
}