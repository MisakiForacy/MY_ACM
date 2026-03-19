#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ans = 0;
        cin >> n;
        string s;
        cin >> s;
        vector<int>a(n+1);
        stack<int>st;
        for (int i=0;i<n;i++){
            if (s[i]=='_'){
                if (st.empty()){
                    st.push(i);
                } else{
                    ans += i-st.top();
                    st.pop();
                }
            } else if (s[i]=='('){
                st.push(i);
            } else{
                ans += i - st.top();
                st.pop();
            }
        }
        cout << ans << '\n';
    }
}