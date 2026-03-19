#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,d,k;
        cin >> n >> d >> k;
        int L[k],R[k];
        for (int i=0;i<k;i++){
            cin >> L[i] >> R[i];
        }
        sort(L,L+k);
        sort(R,R+k);
        int diff,bro,ma,pb,pm;
        bro = 0, ma = 1e9;
        int l,r;
        l = r = 0;
        for (int i=1;i<=n-d+1;i++){
            while (r < k && L[r] <= i+d-1) r ++;
            while (l < k && R[l] < i) l ++;
            diff = r - l;
            if (diff > bro){
                bro = diff;
                pb = i;
            }
            if (diff < ma){
                ma = diff;
                pm = i;
            }
        }
        cout << pb << ' ' << pm << '\n';
    }
}