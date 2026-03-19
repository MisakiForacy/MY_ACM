#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e7+10;
LL P[N], S[N];
int Euler(LL n){
    int k = 0;
    for (LL i=2;i<=n;i++){
        if (!S[i]){
            P[k++] = i;
        }   
        for (LL j=0;j<k;j++){
            if (i * P[j] > n) break; 
            S[i * P[j]] = 1;
            if (i % P[j] == 0) break;
        }
    }
    return k;
}
int main(){
    LL n;
    cin >> n;
    LL cnt = 0;
    int k = Euler(2e7);
    for (int i=0;i<k&&P[i]<=sqrt(n);i++){
        for (int j=i+1;j<k;j++){
            if (P[i]*P[j]>sqrt(n)){
                break;
            } else{
                cnt ++;
            }
        }
        if (P[i]*P[i]<=sqrt(sqrt(n))) cnt ++;
    }
    cout << cnt << '\n';
}