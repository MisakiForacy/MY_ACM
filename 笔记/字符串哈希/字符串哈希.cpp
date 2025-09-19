#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int P = 131;
const int N = 1e5+10;
ULL p[N], h[N];
/*
求一个字符串的哈希值相当于求前缀和
求一个字符串的子串相当于求区间和
*/
// 预处理hash函数的前缀和
void init(){    
    p[0] = 1, h[0] = 0;
    for (int i=1;i<=n;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }
}
// 计算s[l~r]的hash值
ULL get(int l,int r){   
    return h[r] - h[l-1] * p[r-l+1];
}
// 判断两字串是否相同
bool substr(int l1,int r1,int l2,int r2){
    return get(l1,r1) == get(l2,r2);
}