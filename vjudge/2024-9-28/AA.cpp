#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<2*n;i++){
        cout << i/2+i%2 << ' ' << i/2+1 << '\n';
        // printf("%d %d\n%d %d\n",i/2+i%2,i/2+1,i/2+i%2,i/2+2);

    }
    cout << n << ' ' << 1 << '\n';
    int kk = k - 2*n;
    if(kk==0) return 0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||i+1==j) continue;
            cout<<i<<' '<<j<<'\n';
            kk--;
            if(kk==0) return 0;
        }
    }
    for(int j=1;j<=n;j++){
        if(1==j||n==j) continue;
        cout<<n<<' '<<j<<'\n';
        kk--;
        if(kk==0) return 0;
    }
}