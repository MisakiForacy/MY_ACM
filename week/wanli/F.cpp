#include <bits/stdc++.h>
using namespace std;
struct info{
    string a,b;
};
static inline bool cmp(const info &a,const info &b){
    return a.a < b.a;
}
int main(){
    bool flag = true;
    int n = 0,i,j;
    string s,num;
    getline(cin,num);
    for(int i=0;i<num.length();i++){
        if(isdigit(num[i])){
            n *= 10;
            n += num[i] - '0';
        }
    }
    vector<info>name(n);
    for(i=0;i<n;i++){
        getline(cin,name[i].a);
        for(j=0;j<name[i].a.length();j++){
            if(isupper(name[i].a[j])){
                name[i].b.push_back(tolower(name[i].a[j]));
            }
        }
    }
    getline(cin,s);
    sort(name.begin(),name.end(),cmp);
    for(auto &c:name){
        if(c.b == s){
            cout << c.a << endl;
            flag = false;
        }
    }
    if(flag)cout << "No" << endl;
    return 0;
}