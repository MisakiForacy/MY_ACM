#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    vector<int>pre_g(len+1);
    vector<int>pre_r(len+1);
    for (int i=1;i<=len;i++){
        if (s[i-1]=='R') pre_r[i] ++;
        else pre_g[i] ++;
        pre_g[i] = pre_g[i-1] + pre_g[i];
        pre_r[i] = pre_r[i-1] + pre_r[i];
    }
    int lo = 0, hi = len, mx = 0;
    for (hi=1;hi<=len;hi++){
        for (lo=0;lo<hi;lo++){
            if (pre_g[hi]-pre_g[lo]==pre_r[hi]-pre_r[lo]){
                mx = max(mx,hi-lo);
            }
        }
    }
    cout << mx << '\n';
}