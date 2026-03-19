#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s,t;
    cin >> n >> m;
    cin >> s;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        a[i] = (s[i]-'a');
    }
    for (int i=n-1;i>=0;i--){
        if (a[i]==0){
            a[i] = 25;
        } else{
            a[i] -= 1;
            break;
        }
    }
    for (int i=0;i<m-n;i++){
        a.push_back(25);
    }
    int ok = 1;
    for (int i=0;i<n;i++){
        if (s[i]!='a'){
            ok = 0;
        }
    }
    if (ok){
        for (int i=0;i<n-1;i++){
            cout << 'a';
        }
    } else{
        for (int i=0;i<m;i++){
            cout << char(a[i]+'a');
        }
    }
}