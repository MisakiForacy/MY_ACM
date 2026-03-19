#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
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