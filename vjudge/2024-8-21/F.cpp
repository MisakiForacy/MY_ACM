#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
const int N = 1e9+5;

vector<bool> sieve(N,0);
vector<int> pri(N);

int main(){
    int n;
    cin >> n;
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            pri[k++] = i;
        }
        for (int j=0;j<k;j++){
            if (i * pri[j] > n) break;
            sieve[i * pri[j]] = 1;
            if (! (i % pri[j])) break;
        }
    }
    cout << k << '\n';
}