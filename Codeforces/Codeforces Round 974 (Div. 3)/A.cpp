#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        int t = 0,cnt = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (a[i]>=k){
                t += a[i];
            } else if (a[i]==0 && t){
                cnt ++;
                t --;
            }
        }
        cout << cnt << '\n';
    }
}