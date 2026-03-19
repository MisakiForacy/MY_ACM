#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n,i;
int main(){
    cin >> n >> s1 >> s2;
    for(i=0;i<n;i++){
        if(s1[i]<s2[i]){
            cout << -1;
            return 0;
        }
    }
    cout << s2;
    return 0;
}