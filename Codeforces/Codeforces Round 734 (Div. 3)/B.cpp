#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int k = 2;
        string s;
        cin >> s;
        struct node{
            int x,id,c;
        };
        // vector<node> a(n);
        // vector<int> ans(n,0);
        vector<vector<int>> b(s.size(),vector<int>(0));
        map<int,vector<int>> mp;
        for (int i = 0;i < s.size();i ++){
            mp[s[i]].push_back(i);
        }
        int p = 0;
        for (auto [x, v] : mp){
            // cout << x << ' ' << v.size() << ' ' << (v.size() >= k) << '\n';
            if (v.size() >= k){
                int pos = 0;
                int res = k - b[p].size();
                // cout << res << '\n';
                if (res != k){
                    for (int i = 0;i < res;i ++){
                        b[p].push_back(v[pos ++]);
                    }
                    if (b[p].size() == k) p ++;
                    for (int i = 0;i < k - res;i ++){
                        b[p].push_back(v[pos ++]);
                    }
                    if (b[p].size() == k) p ++;
                } else{
                    for (int i = 0;i < k;i ++){
                        b[p].push_back(v[pos ++]);
                    }
                }
            } else{
                int pos = 0;
                int res = k - b[p].size();
                if (v.size() <= res){
                    for (int i = 0;i < v.size();i ++){
                        b[p].push_back(v[pos ++]);
                    }
                    if (b[p].size() == k) p ++;
                } else{
                    for (int i = 0;i < res;i ++){
                        b[p].push_back(v[pos ++]);
                    }
                    if (b[p].size() == k) p ++;
                    for (int i = 0;i < v.size() - res;i ++){
                        b[p].push_back(v[pos ++]);
                    }
                    if (b[p].size() == k) p ++;
                }
            }
        }
        if (b[p].size() == k) p ++;
        cout << p << '\n';
    }
}