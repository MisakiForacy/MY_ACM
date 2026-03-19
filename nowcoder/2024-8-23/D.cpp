#include <bits/stdc++.h>
using namespace std;
int sieve[200005];
int prime[200005];
int s[400005];
int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return k;
}
int main(){
    int k = Euler(200005);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int,int> t2;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            if (t1[a[i]]==1){
                t2[a[i]] = 1;
            }
        }
        for (int i=0;i<k;i++){
            if (t2[prime[i]]==0){
                cout << prime[i] << '\n';
            }
        }
    }
}