#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ll x,y;
    cin >> x >> y;
    set<ll> a,b,c;
    for (int i=1;i<=sqrt(x);i++){
        if (x%i==0){
            a.insert(i);
            a.insert(x/i);
        }
    }
    for (int i=1;i<=sqrt(y);i++){
        if (y%i==0){
            b.insert(i);
            b.insert(y/i);
        }
    }
    ll nu = x*y;
    for (auto n1:a){
        for (auto n2:b){
            if (nu%(n1*n2)==0){
                c.insert(n1*n2);
            }
        }
    }
    cout << c.size() << '\n';
}