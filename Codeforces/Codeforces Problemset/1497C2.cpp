#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        n -= (k-3);
        for (int i=3;i<k;i++){
            cout << 1 << ' ';
        }
        if (n&1){
            printf("%d %d %d\n",n/2,n/2,1);
        } else{
            if ((n/2)&1){
                printf("%d %d %d\n",n/2-1,n/2-1,2);
            } else{
                printf("%d %d %d\n",n/2,n/4,n/4);
            }
        }
    }
}