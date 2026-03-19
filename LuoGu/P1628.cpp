#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    multiset<string>st;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s;
        st.insert(s);
    }
    string t;
    cin >> t;
    for (auto x:st){
        if (x.substr(0,t.length())==t){
            cout << x << '\n';
        }
    }
}