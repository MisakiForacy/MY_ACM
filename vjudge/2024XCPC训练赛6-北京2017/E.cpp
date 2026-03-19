#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    double m,n,x;
    while (cin >> m >> n >> x){
        vector<int> a(n);
        vector<int> b(n,0);
        int co = 0, ic = 0;
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        for (int i=1;i<=x;i++){
            for (int j=0;j<n;j++){
                if (m > 0){
                    if (i%a[j] && !b[j]){
                        b[j] = 1;
                        m --;
                    } else if (i%a[j]==0 && b[j]){
                        b[j] = 0;
                    } else if (i%a[j]==0){
                        m --;
                    }
                }
            }
        }
        for (int i=0;i<n;i++){
            ic += b[i];
        }
        cout << m << ' ' << ic << '\n';
    }
}