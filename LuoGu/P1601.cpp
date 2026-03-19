#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N (i64)(1e6+10)
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long i64;
static inline i64 Add(i64 len);
static inline i64 Switch1(string num);
static inline i64 Switch2(string num);
string num1, num2;
vector<i64>s1, s2;
i64 len,i,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> num1 >> num2;
    len = max(Switch1(num1),Switch2(num2));
    s1.resize(len+1), s2.resize(len+1);
    len = Add(len);
    for(i=len-1;i>-1;i--){
        cout << s1[i];
    }
    cout << endl;
    return 0;
}
static inline i64 Add(i64 len){
    x = 0;
    for(i=0;i<len;i++){
        s1[i] += s2[i] + x;
        x = s1[i] / 10;
        s1[i] = s1[i] % 10;
    }
    if(x != 0){
        s1[i] = x;
        return len + 1;
    }
    else return len;
}
static inline i64 Switch1(string num){
    for(i=num.length()-1;i>-1;i--){
        s1.push_back(num[i]-'0');
    }
    return num.length();
}
static inline i64 Switch2(string num){
    for(i=num.length()-1;i>-1;i--){
        s2.push_back(num[i]-'0');
    }
    return num.length();
}