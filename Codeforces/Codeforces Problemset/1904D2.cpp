#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n;
        int ok = 1;
        cin >> n;
        vector<LL> a(n+2,0);
        vector<LL> b(n+2,0);
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        vector<int> R(n+1,0);
        vector<int> L(n+1,0);
        stack<int> st;
        for (int i=n;i>=1;i--){
            while (!st.empty() && (b[st.top()]>b[i] || a[st.top()]<b[i])) st.pop();
            if (a[i] == b[i]) R[i] = i;
            else R[i] = st.empty()?0:st.top();
            st.push(i);
        }
        while (st.size()) st.pop();
        for (int i=1;i<=n;i++){
            while (!st.empty() && (b[st.top()]>b[i] || a[st.top()]<b[i])) st.pop();
            if (a[i] == b[i]) L[i] = i;
            else L[i] = st.empty()?0:st.top();
            st.push(i);
        }
        for (int i=1;i<=n;i++){
            if (!R[i] && !L[i]){
                ok = 0;
                break;
            }
        }
        for (int i=1;i<=n;i++) cout << R[i] << " \n"[i==n];
        for (int i=1;i<=n;i++) cout << L[i] << " \n"[i==n];
        cout << (ok?"YES\n":"NO\n");
    }
}