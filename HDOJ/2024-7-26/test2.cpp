#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll m = n + 1;
    if(n & 1)
    {
    	m >>= 1;
        if(m & 1) cout << n << endl;
        else cout << n * (m / 2) << endl;
    }
    else
    {
    	n >>= 1;
        if(n & 1) cout << m << endl;
        else cout << m * (n / 2) << endl;
    }
}
