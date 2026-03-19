#include <bits/stdc++.h>
using namespace std;
string solve(int lo,int hi,string s,int t){
    string ans = "";
    int ck = 0;
    for (int i=lo;i<hi;i++){
        if (s[i] == '['){
            lo = i;
            ck ++;
            int ti;
            if (isdigit(s[i+1])&&isdigit(s[i+2])){
                string nu = "";
                nu.push_back(s[i+1]);
                nu.push_back(s[i+2]);
                ti = stoi(nu);
                lo += 2;
            } else{
                ti = s[i+1]-'0';
                lo += 1;
            }
            while (ck){
                i ++;
                if (s[i]=='[') ck ++;
                else if (s[i]==']') ck --;
            }
            ans.append(solve(lo+1,i,s,ti));
        } else{
            ans.push_back(s[i]);
        }
    }
    string ss = ans;
    for (int i=1;i<t;i++){
        ans.append(ss);
    }
    return ans;
}
int main(){
    string s;
    cin >> s;
    string ans;
    ans = solve(0,s.length(),s,1);
    cout << ans << '\n';    
}