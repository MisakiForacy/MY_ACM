#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;

int main(){
    int T = 1;
    cin >> T;
    while (T --){
        int n,k;
        cin >> n >> k;
        for (int i = n - k;i <= n;i ++){
            cout << i << ' ';
        }
        for (int i = n - k - 1;i >= 1;i --){
            cout << i << ' ';
        }
        cout << '\n';
    }
}