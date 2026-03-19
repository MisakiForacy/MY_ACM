#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag = true;
    char c;
    int n,i,j;
    string s;
    cin >> c >> n;
    vector<vector<char>>a(n,vector<char>(n,' '));
    vector<vector<char>>b(n,vector<char>(n,' '));
    getline(cin,s);
    for(j=0;j<n;j++){
        if(s[j]=='@')a[0][j]=c;
    }
    for(i=0;i<n;i++){
        getline(cin,s);
        for(j=0;j<n;j++){
            if(s[j]=='@')a[i][j]=c;
        }
    }
    for(i=n-1;i>-1;i--){
        for(j=n-1;j>-1;j--){
            b[i][j] = a[n-i-1][n-j-1];
            if(flag&&b[i][j]!=a[i][j])flag = false;
        }
    }
    if(flag)cout<<"bu yong dao le"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}