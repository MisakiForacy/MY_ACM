#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ull mod = 1e17+9;
const int N = 1e5+5;
const int P = 13331;
ull p[N],h[N];
void init(string s){
    int n = s.length();
    p[0] = 1,h[0] = 0;
    for (int i=1;i<=n;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }
}
ull get(ll l,ll r){
    return h[r] - h[l-1] * p[r-l+1];
}
bool substr(ll l1,ll r1,ll l2,ll r2){
    return get(l1,r1) == get(l2,r2);
}
int main(){
    int T;
    string a,c;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cin >> a >> c;
        string b1,b2;
        for (int i=0;i<n;i++){
            cin >> b1 >> b2;
            for (int i=0;i<a.length()-b1.length();i++){
                if (a[])
            }
        }
    }
}