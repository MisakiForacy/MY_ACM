#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n,i,j,l,r;
string str,s;
int main(){
    while(getline(cin,s)&&s.length()!=0){
        str.append(s);
    }
    l = 1, r = 0;
    for(i=0;i<str.length();i++){
        if(str[i] == '\"' && l){
            str[i] = '`';
            str.insert(i,1,'`');
            l = 0;
            r = 1;
        }
        else if(str[i] == '\"' && r){
            str[i] = '\'';
            str.insert(i,1,'\'');
            l = 1;
            r = 0;
        }
    }
    cout << str;
}