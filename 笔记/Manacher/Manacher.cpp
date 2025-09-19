#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

/*
    马拉车算法：找字符串中最长回文串
*/

// string Switch(string s){
//     /*
//         将字符串s转换
//         原s为abbcac,
//         转换后结果形如$#a#b#b#c#a#c#^
//         原因
//         该算法原本只能处理长度为奇数的回文串
//         如此转换后可以同时处理奇数串和偶数串
//         让所有回文串长度都为奇数
//     */
//     string t = "&";
//     for (char &c : s){
//         t += "#";
//         t += c;
//     }
//     t += "#^";
//     return t;
// }

// int Manacher(string s){
//     string t = Switch(s);
//     vector<int> p(siz(t), 0);
//     int mr = 0, mid;
//     for (int i = 1;i < siz(t);i ++){
//         if (i < mr) p[i] = min(p[2 * mid - i], mr - i);
//         else p[i] = 1;
//         while (t[i - p[i]] == t[i + p[i]]) p[i] ++;
//         if (i + p[i] > mr){
//             mr = i + p[i];
//             mid = i;
//         }
//     }
//     int len = 0;
//     for (int i = 1;i < siz(t);i ++){
//         len = max(len, p[i] - 1);
//     }
//     return len;
// }

/*
=============以上是ACWing的教程，以下是自己的优化写法，可以节省一倍空间================
=============同时省去转换的步骤=================
*/

int Manacher(string s){
    s = ' ' + s;
    vector<int> p(siz(s), 0);
    int R = 0, mid, Max = 0;
    for (int i = 1;i < siz(s);i ++){
        if (i < R) p[i] = min(p[2 * mid - i], R - i);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]]) p[i] ++;
        if (i + p[i] > R){
            R = i + p[i];
            mid = i;
        }
        Max = max(Max, p[i] * 2 - 1);
    }
    R = 0;
    for (int i = 1;i < siz(s) - 1;i ++){
        if (s[i] != s[i + 1]) continue;
        if (i < R) p[i] = min(p[2 * mid - i], R - i);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i] + 1]) p[i] ++;
        if (i + p[i] > R){
            R = i + p[i];
            mid = i;
        }
        Max = max(Max, p[i] * 2);
    }
    return Max;
}

int main(){
    string s;
    cin >> s;
    cout << Manacher(s) << '\n';
}