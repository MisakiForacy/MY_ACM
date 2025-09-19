#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<LL> a(n), ans;
    map<LL,LL> mp;
    for (int i = 0;i < n;i ++) cin >> a[i], mp[a[i]] ++;
    sort(all(a));
    int Max = 1;
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < 50;j ++){
            if (mp.count(a[i] + (1LL << j)) && mp.count(a[i] + (1LL << (j + 1)))){
                Max = 3;
                ans.push_back(a[i]);
                ans.push_back(a[i] + (1LL << j));
                ans.push_back(a[i] + (1LL << (j + 1)));
                cout << Max << '\n';
                for (int i = 0;i < Max;i ++){
                    cout << ans[i] << " \n"[i == Max - 1];  
                }
                return 0;
            }
        }
    }
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < 50;j ++){
            if (mp.count(a[i] + (1LL << j))){
                Max = 2;
                ans.push_back(a[i]);
                ans.push_back(a[i] + (1LL << j));
                cout << Max << '\n';
                for (int i = 0;i < Max;i ++){
                    cout << ans[i] << " \n"[i == Max - 1];  
                }
                return 0;
            }
        }
    }
    cout << Max << '\n';
    ans.push_back(a[0]);
    for (int i = 0;i < Max;i ++){
        cout << ans[i] << " \n"[i == Max - 1];  
    }
}