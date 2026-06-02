#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin >> n;
    bool c,a;
    vector<vector<ll>>triangle(n+1,vector<ll>(n+2,0));
    vector<ll>coe,expa,expb;
    triangle[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i+1;j++){
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    for(int i=1;i<=n+1;i++){
        coe.push_back(triangle[n][i]);
    }
    for(int i=0;i<=n;i++){
        expa.push_back(n-i);
        expb.push_back(i);
    }
    for(int i=0;i<=n;i++){
        c = false, a = false;
        if(coe[i]!=1){
            cout << coe[i];
            c = true;
        }
        if(expa[i]!=0){
            if(c)cout << "*a";
            else cout << "a";
            if(expa[i]!=1)cout << "^" << expa[i];
            a = true;
        }
        if(expb[i]!=0){
            if(c|a)cout << "*b";
            else cout << "b";
            if(expb[i]!=1)cout << "^" << expb[i];
        }
        if(a)cout << "+";
    }
}