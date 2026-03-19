#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i=0;i<=n/5;i++){
        if ((n-i*5)%3==0){
            ans = min(ans,i + (n-i*5)/3);
        }
    }
    cout << (ans == INT_MAX ? -1:ans) << '\n';
}