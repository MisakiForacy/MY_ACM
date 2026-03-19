#include <bits/stdc++.h>
using namespace std;
struct bout{
    int ca,fa,cb,fb;
};
int main(){
    int la,lb,n;
    int call,va=0,vb=0;
    int i,j;
    cin >> la >> lb >> n;
    vector<bout>s(n);
    for(i=0;i<n;i++)cin >> s[i].ca >> s[i].fa >> s[i].cb >> s[i].fb;
    for(i=0;i<n;i++){
        call = s[i].ca + s[i].cb;
        if(s[i].fa==call&&s[i].fb!=call)la--,va++;
        else if(s[i].fa!=call&&s[i].fb==call)lb--,vb++;
        if(la<0||lb<0)break;
    }
    if(la<0)cout<<'A'<<endl<<vb<<endl;
    else cout<<'B'<<endl<<va<<endl;
    return 0;
}