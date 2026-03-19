#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.length();
        for (int i=0;i<n;i++){
            int id = i;
            int mx = s[i] - '0';
            for (int j=i;j<=min(i+9,n-1);j++){
                if (s[j]-'0'-(j-i) > mx){
                    mx = s[j] - '0' - (j-i);
                    id = j;
                }
            }
            for (int j=id;j>i;j--){
                swap(s[j],s[j-1]);
            }
            if (id != i){
                s[i] = s[i] - (id-i);
            }
        }
        cout << s << '\n';
    }
}