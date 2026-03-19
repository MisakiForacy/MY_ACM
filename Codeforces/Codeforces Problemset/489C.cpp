#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,s;
    cin >> n >> s;
    if (n*9<s || (n>1&&s<1)){
        cout << -1 << ' ' << -1 << '\n';
    } else{
        string ss,rs;
        ss = rs = "";
        int lst = 1;
        int tp_s = s, tp_n = n;
        tp_s -= lst;
        tp_n -= 1;
        int len = tp_s/9;
        int rst = tp_s%9;
        if (len < tp_n){
            int zro = tp_n - len - 1;
            while (len--) ss.push_back('9');
            ss.push_back(rst+'0');
            while (zro--) ss.push_back('0');
            ss.push_back(lst+'0');
        } else{
            lst += rst;
            while (len--) ss.push_back('9');
            ss.push_back(lst+'0');
        }
        reverse(ss.begin(),ss.end());
        tp_s = s, tp_n = n;
        len = tp_s/9;
        rst = tp_s%9;
        if (rst){
            int zro = tp_n - len - 1;
            while (len--) rs.push_back('9');
            rs.push_back(rst+'0');
            while (zro--) rs.push_back('0');
        } else{
            int zro = tp_n - len;
            while (len--) rs.push_back('9');
            while (zro--) rs.push_back('0');
        }
        cout << ss << ' ' << rs << '\n';
    }
}