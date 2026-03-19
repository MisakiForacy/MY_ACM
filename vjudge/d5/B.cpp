#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    getchar();
    while (T--){
        string s,str;
        getline(cin,s);
        s += ' ';
        str = "";
        vector<string>ans;
        for (int i=0;i<s.length();i++){
            if (s[i]!=' '){
                str.push_back(s[i]);
            } else{
                reverse(str.begin(),str.end());
                ans.push_back(str);
                str = "";
            }
        }
        for (int i=0;i<ans.size();i++){
            cout << ans[i] << " \n"[i==ans.size()-1];
        }
    }
}