#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,cnt = 0;
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        for (int i=1;i<n-1;i++){
            if (s1[i-1]=='.'&&s1[i+1]=='.'&&s1[i]=='.'&&s2[i-1]=='x'&&s2[i+1]=='x'&&s2[i]=='.'){
                cnt ++;
            }
            if (s2[i-1]=='.'&&s2[i+1]=='.'&&s2[i]=='.'&&s1[i-1]=='x'&&s1[i+1]=='x'&&s1[i]=='.'){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}