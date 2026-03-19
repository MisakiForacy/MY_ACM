#include <bits/stdc++.h>
using namespace std;
const int nn[10] = {6,2,5,5,4,5,6,3,7,6};
int count(int n){
    if (!n) return 6;
    int cnt = 0;
    while (n){
        cnt += nn[n%10];
        n /= 10;
    }
    return cnt;
}
int main(){
    int n,ans=0;
    cin >> n;
    n -= 4;
    for (int i=0;i<=1000;i++){
        for (int j=0;j<=1000;j++){
            int cnt = 0;
            cnt += count(i);
            cnt += count(j);
            cnt += count(i+j);
            if (cnt==n){
                ans ++;
            }
        }
    }
    cout << ans << '\n';
}