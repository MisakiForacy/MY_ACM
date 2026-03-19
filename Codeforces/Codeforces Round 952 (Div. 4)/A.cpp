#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
int main(){
    int T;
    string a,b;
    cin >> T;
    while (T --){
        cin >> a >> b;
        cout << b[0] << a[1] << a[2] << " " << a[0] << b[1] << b[2] << '\n';
    }
}