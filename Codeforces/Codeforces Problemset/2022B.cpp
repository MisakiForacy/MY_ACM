#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n >> x;
        vector<LL> a(n);
        LL tot = 0;
        LL Max = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            Max = max(Max,a[i]);
            tot += a[i];
        }
        cout << max(tot/x+(tot%x?1:0),Max) << '\n';
    }
}