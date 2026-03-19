#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    set<LL> st;
    vector<LL> arr(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    for (int i=1;i<n;i++){
        LL a,b,c;
        a = arr[i-1];
        b = arr[i];
        c = a ^ b;
        st.insert(a), st.insert(b), st.insert(c);
        st.insert(a|b), st.insert(a|c), st.insert(b|c);
        st.insert(a&b), st.insert(a&c), st.insert(b&c);
        st.insert(a^c), st.insert(b^c), st.insert(0);
    }
    cout << st.size() << '\n';
}