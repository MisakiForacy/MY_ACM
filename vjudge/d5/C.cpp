#include <iostream>
#include <stack>
#include <cmath>
#include <stdio.h>
using namespace std;
typedef double db;
bool is_op(char s){
    return (s=='+'||s=='-'||s=='*'||s=='/');
}
int to_int(string s){
    int n=0;
    for (int i=0;i<s.length();i++){
        n += (s[i]-'0')*pow(10,s.length()-i-1);
    }
    return n;
}
int main(){
    int las = 1,las_op = 1;
    char s;
    stack<db>stk;
    string num = "";
    while (1){
        s = getchar();
        if (isdigit(s)){
            num.push_back(s);
            las = 1;
        } else if (is_op(s)){
            las_op = (s=='+'?1:(s=='-'?2:(s=='*'?3:4)));
            las = 0;
        } else{
            if (las){
                if (las_op<3){
                    stk.push((1.0*(las_op==1?1:-1)*to_int(num)));
                } else if (las_op==3){
                    stk.top() *= (1.0*to_int(num));
                } else{
                    stk.top() /= (1.0*to_int(num));
                }
                num = "";
            }
        }
        if (s=='\n'){
            if (las_op==1 && stk.top()==0 && stk.size()==1){
                break;
            }
            db ans = 0;
            while (!stk.empty()){
                ans += stk.top();
                stk.pop();
            }
            printf("%.2f\n",ans);
            las_op = 1;
        }
    }
}