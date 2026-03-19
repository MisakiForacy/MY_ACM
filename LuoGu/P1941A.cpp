#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,k;
        int cnt = 0;
        cin >> n >> m >> k;
        vector<int> a(n),b(m);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<m;i++) cin >> b[i];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (a[i] + b[j] <= k){
                    cnt ++;
                }
            }
        }
        cout << cnt << '\n';
    }
}