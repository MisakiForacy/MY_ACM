#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a),[&](string x,string y){
        return x.size() < y.size();
    });
    int ok = 1;
    for (int i = 0;i < n - 1;i ++){
        if (a[i + 1].find(a[i]) == -1){
            ok = 0;
        }
    }
    if (ok){
        cout << "YES\n";
        for (int i = 0;i < n;i ++){
            cout << a[i] << '\n';
        }
    } else{
        cout << "NO\n";
    }
}