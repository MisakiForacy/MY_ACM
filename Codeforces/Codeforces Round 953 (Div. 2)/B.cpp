#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll n,a,b;
    cin >> T;
    while (T--){
        cin >> n >> a >> b;
        if (b<=a){
            cout << n*a << '\n';
        } else{
            if (b-n>=a){
                cout << (b+(b-n+1))*n/2 << '\n';
            } else{
                cout << (a+b)*(b-a+1)/2+a*(n-(b-a+1)) << '\n';
            }
        }
    }
}