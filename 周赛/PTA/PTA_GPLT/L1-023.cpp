#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    int G=0,P=0,L=0,T=0;
    string str;
    cin >> str;
    transform(str.begin(),str.end(),str.begin(),::toupper);
    for(i=0;i<str.length();i++){
        if(str[i]=='G')G++;
        else if(str[i]=='P')P++;
        else if(str[i]=='L')L++;
        else if(str[i]=='T')T++;
    }
    while(G+P+L+T!=0){
        if(G!=0)cout<<'G',G--;
        if(P!=0)cout<<'P',P--;
        if(L!=0)cout<<'L',L--;
        if(T!=0)cout<<'T',T--;
    }
    return 0;
}