#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL inf = INT_MAX;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    map<int,int> mp;
    for (int i = 0;i < n;i ++){
        mp[s[i] - '0'] ++;
    }
    int ans = inf;
    if (mp[0] >= 2){ // 00
        int cnt = 0,len = 0;
        for (int i = n - 1;i >= 0;i --){
            if (s[i] == '0'){
                cnt ++;
                len += n - i - cnt;
            }
            if (cnt == 2){
                ans = min(ans,len);
                break;
            }
        }
    }
    if (mp[2] >= 1 && mp[5] >= 1){
        int c2,c5,len;
        c2 = c5 = len = 0;
        for (int i = n - 1;i >= 0;i --){
            if (!c2 && s[i] == '2'){
                if (i == 0){
                    int id = 1;
                    while (s[id ++] == '0') len ++;
                }
                len += n - i - 1 - c5;
                c2 = 1;
            }
            if (!c5 && s[i] == '5'){
                if (i == 0){
                    int id = 1;
                    while (s[id ++] == '0') len ++;
                }
                len += n - i - 1;
                c5 = 1;
            }
            if (c2 && c5){
                ans = min(ans,len);
                break;
            }
        }
    }
    if (mp[7] >= 1 && mp[5] >= 1){
        int c7,c5,len;
        c7 = c5 = len = 0;
        for (int i = n - 1;i >= 0;i --){
            if (!c7 && s[i] == '7'){
                if (i == 0){
                    int id = 1;
                    while (s[id ++] == '0') len ++;
                }
                len += n - i - 1 - c5;
                c7 = 1;
            }
            if (!c5 && s[i] == '5'){
                if (i == 0){
                    int id = 1;
                    while (s[id ++] == '0') len ++;
                }
                len += n - i - 1;
                c5 = 1;
            }
            if (c7 && c5){
                ans = min(ans,len);
                break;
            }
        }
    }
    if (mp[5] >= 1 && mp[0] >= 1){
        int c5,c0,len;
        c5 = c0 = len = 0;
        for (int i = n - 1;i >= 0;i --){
            if (!c5 && s[i] == '5'){
                len += n - i - 1 - c0;
                c5 = 1;
            }
            if (!c0 && s[i] == '0'){
                len += n - i - 1;
                c0 = 1;
            }
            if (c5 && c0){
                ans = min(ans,len);
                break;
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}