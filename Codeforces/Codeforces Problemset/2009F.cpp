#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n'
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,q;
        cin >> n >> q;
        vector<ll> a(n+1,0);
        vector<ll> sum(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
        ll l,r;
        for (int i=1;i<=q;i++){
            cin >> l >> r;
            ll left = n - (l-1)%n;
            ll right = r%n;
            ll mid = ((r-l+1) - left - right)/n;
            ll pre_len = n - (r-1) / n;
            ll suf_len = (l-1) / n;
            ll left_sum, right_sum;
            if (left > suf_len){
                left_sum = (sum[n]-sum[0]) - (sum[n-left+suf_len]-sum[(l-1)/n]);
            } else{
                left_sum = sum[(l-1)/n] - sum[(l-1)/n-left];
            }
            if (right > pre_len){
                right_sum = (sum[n]-sum[0]) - (sum[(r-1)/n]-sum[right-pre_len]);
            } else{
                right_sum = sum[(r-1)/n+right] - sum[(r-1)/n];
            }
            cout << left_sum + right_sum + mid*(sum[n]-sum[0]) << '\n';
        }
    }
}