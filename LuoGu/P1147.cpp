#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll>prefix(n+1,0);
    for (int i=1;i<=n;i++){
        prefix[i] = prefix[i-1] + i;
    }
    int lo, hi;
    for ()
}