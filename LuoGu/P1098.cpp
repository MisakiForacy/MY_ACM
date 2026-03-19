#include <bits/stdc++.h>
using namespace std;
int main(){
    int p1,p2,p3;
    string s;
    cin >> p1 >> p2 >> p3;
    cin >> s;
    vector<string>add;
    vector<int>idx;
    for (int i=0;i<int(s.length());i++){
        if ((s[i]=='-'&&s[i-1]<s[i+1]&&isalpha(s[i-1])&&isalpha(s[i+1])) || (isdigit(s[i-1])&&isdigit(s[i+1]))){
            idx.push_back(i);
            string str = "";
            for (int c=(p3==1?s[i-1]+1:s[i+1]-1);(p3==1?c<s[i+1]:c>s[i-1]);(p3==1?c++:c--)){
                for (int j=0;j<p2;j++){    
                    if (p1==1 || ('0'<=c&&c<='9'&&p1!=3)){
                        str.push_back(char(c));
                    } else if (p1==2){
                        str.push_back(char(c-32));
                    } else{
                        str.push_back('*');
                    }
                }
            }
            add.push_back(str);
        }
    }
    idx.push_back(-1);
    int k = 0;
    string ans = "";
    for (int i=0;i<int(s.length());i++){
        if (i!=idx[k]){
            ans.push_back(s[i]);
        } else{
            ans.append(add[k]);
            k ++;
        }
    }
    cout << ans << '\n';
}