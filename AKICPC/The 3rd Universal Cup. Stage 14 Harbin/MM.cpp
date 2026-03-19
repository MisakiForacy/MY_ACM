#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int f(int a,int b){
    int i = b;
    while (i >= 2){
        if (!(a%i)){
            return a / i;
        } else{
            i --;
        }
    }
    return a;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i=1;i<=n;i++){
            ans += f(n,i);
        }
        cout << ans << '\n';
    }
}