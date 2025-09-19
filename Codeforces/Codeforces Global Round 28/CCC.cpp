#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string XOR(string s1,string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for (int i=0;i<s2.size();i++){
        if (s1[i] == s2[i]){
            s1[i] = '0';
        } else{
            s1[i] = '1';
        }
    }
    reverse(s1.begin(),s1.end());
    return s1;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        string s,mx;
        cin >> s;
        int n = s.length();
        for (int i=0;i<n;i++){
            mx.push_back('0');
        }
        int id = -1;
        for (int i=0;i<n;i++){
            if (s[i] == '0'){
                id = i;
                break;
            }
        }
        if (id == -1){
            printf("1 %d 1 1\n",n);
        } else{
            for (int i=0;i<n-id;i++){

            }
        }
    }
}