#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        int la,ra,lb,rb;
        int ok = 1;
        la = lb = 0, ra = rb = n-1;
        while (la < ra){
            if (min(a[la],a[ra])!=min(b[lb],b[rb]) || max(a[la],a[ra])!=max(b[lb],b[rb])){
                ok = 0;
                break;
            } else{
                if (a[la]==b[lb]){
                    la ++, lb ++;
                } else{
                    la ++, rb --;
                }
            }
        }
        cout << (ok?"Bob\n":"Alice\n");
    }
}