#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool isprime(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        if (isprime(m)){
            vector<int> lst;
            int mid = n / 2;
            lst.push_back(mid*m);
            for (int i=0;i<mid;i++){
                lst.push_back(i*m);
                lst.push_back((n-i-1)*m);
            }
            for (int i=0;i<n;i++){
                for (int j=1;j<=m;j++){
                    cout << lst[i] + j << " \n"[j==m];
                }
            }
        } else{
            int k = 1;
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    cout << k ++ << " \n"[j==m-1];
                }
            }
        }
    }
}