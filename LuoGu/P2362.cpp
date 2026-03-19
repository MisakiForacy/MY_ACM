#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> mp;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        for (int i=0;i<(1 << n);i++){
            int ok = 1;
            vector<int> tmp;
            for (int j=n-1;j>=0;j--){
                if ((i >> j) & 1){
                    tmp.push_back(a[j]);
                }
            }
            for (int j=1;j<tmp.size();j++){
                if (tmp[j] > tmp[j-1]){
                    ok = 0;
                    break;
                }
            }
            if (ok){
                mp[tmp.size()] ++;
            }
        }
        int Max = 0, cnt = 0;
        for (auto [k,v]:mp){
            Max = k, cnt = v;
        }
        cout << Max << ' ' << cnt << '\n';
    }
}