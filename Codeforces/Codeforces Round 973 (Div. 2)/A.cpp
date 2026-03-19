#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y;
        cin >> n >> x >> y;
        cout << n / min(x,y) + (n%min(x,y)?1:0) << '\n';
    }
}