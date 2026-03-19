#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (i%int(sqrt(sqrt(i)))==0){
            cnt ++;
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    cout << cnt << '\n';
}