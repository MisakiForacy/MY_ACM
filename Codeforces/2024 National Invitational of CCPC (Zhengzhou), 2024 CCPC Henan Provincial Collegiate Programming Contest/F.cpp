#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
set<char>m;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        m.clear();
        cin >> s;
        if(s.length()!=5){
            continue;
        }
        else if(s[2]!=s[4]){
            continue;
        }
        else{
            m.insert(s[0]);
            m.insert(s[1]);
            m.insert(s[2]);
            m.insert(s[3]);
            if(m.size()==4)cnt ++;
        }
    }
    cout << cnt << endl;
}