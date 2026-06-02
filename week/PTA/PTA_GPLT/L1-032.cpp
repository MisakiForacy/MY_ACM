#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char s;
    int i,j,len;
    string str;
    cin >> n >> s;
    getchar();
    getline(cin,str);
    len = str.length();
    if(len<=n){
        for(i=0;i<n-len;i++){
            cout << s;
        }
        for(i=0;i<len;i++){
            cout << str[i];
        }
    }
    else{
        for(i=len-n;i<len;i++){
            cout << str[i];
        }
    }
    return 0;
}