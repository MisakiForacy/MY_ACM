#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<int>a){
    int len = a.size();
    vector<int>b(len-1);
    for (int i=1;i<len;i++){
        b[i-1] = __gcd(a[i],a[i-1]);
    }
    for (int i=1;i<len-1;i++){
        if (b[i] < b[i-1]) return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    vector<int>a(n),gcd(n-1);
    cin >> a[0];
    for (int i=1;i<n;i++){
        cin >> a[i];
        gcd[i-1] = __gcd(a[i],a[i-1]);
    }
    int idx = -1;
    for (int i=1;i<gcd.size();i++){
        if (gcd[i] < gcd[i-1]){
            idx = i;
            break;
        }
    }
    if (idx == -1){
        cout << "YES\n";
    } else{
        int ok = 0;
        vector<int>a1(a.begin(),a.end());
        vector<int>a2(a.begin(),a.end());
        vector<int>a3(a.begin(),a.end());
        a1.erase(a1.begin()+idx-1);
        a2.erase(a2.begin()+idx);
        a3.erase(a3.begin()+idx+1);
        if (check(a1)||check(a2)||check(a3)){
            ok = 1;
        }
        cout << (ok?"YES\n":"NO\n");
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}