#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++){
        LL ans1 = 0, ans2 = 0, ans3 = 0;
        for(int j = 0; j < 32; j ++){
            int t1 = a[i] >> j & 1;
            int t2 = a[i - 1] >> j & 1;
            if(t1 == 1 && t2 == 0){
                ans1 += 1ll << j;
            }
            else if(t1 == 0 && t2 == 1){
                ans2 += 1ll << j;
            }
            else if(t1 == 1 && t2 == 1){
                ans3 += 1ll << j;
            }
        }

        for(int j = 0; j < 8; j ++){
            int sum = 0;
            for(int k = 0; k < 3; k ++){
                if(j >> k & 1) {
                    if(k == 0) sum += ans3;
                    if(k == 1) sum += ans2;
                    if(k == 2) sum += ans1;
                }
            }
            mp[sum] = 1;
        }
    }
    cout << mp.size() << endl;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
}