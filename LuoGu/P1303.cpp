#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N (i64)(1e6+10)
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long i64;
vector<i64>s1,s2,s3;
string num1,num2;
i64 x,i,j,len1,len2,len;
static inline i64 Switch1(string num);
static inline i64 Switch2(string num);
static inline i64 Multiply(i64 len);
int main(){
    cin >> num1 >> num2;
    len = max(Switch1(num1),Switch2(num2));
    s1.resize(len,0), s2.resize(len,0), s3.resize(len*2,0);
    len = Multiply(len);
    if(num1=="0" || num2=="0")len = 1;
    for(i=len-1;i>-1;i--){
        cout << s3[i];
    }
    cout << endl;
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
static inline i64 Multiply(i64 len){
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            s3[j] += s1[j] * s2[i] * pow(10,i);
        }
    }
    x = 0;
    for(j=0;j<len;j++){
        s3[j] += x;
        x = s3[j] / 10;
        s3[j] = s3[j] % 10;
    }
    while(x != 0){
        s3[j] += x;
        x = s3[j] / 10;
        s3[j] = s3[j] % 10;
        j++;
    }
    return j;
}