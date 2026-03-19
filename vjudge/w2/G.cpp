#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,k,mi,odd,eve;
        cin >> n >> k;
        vector<int>a(n);
        map<int,int> mp;
        mi = k, odd = eve = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            mi = min(mi,(a[i]%k?k-a[i]%k:0));
            if (a[i]&1) odd ++;
            else eve ++;
        }
        if (k==4){
            if (odd && eve) mi = min(mi,1);
            if (eve > 1) mi = 0;
            if (odd > 1) mi = min(mi,2);
        }
        cout << mi << '\n';
    }
}