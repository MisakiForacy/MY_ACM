#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> st(n);
        vector<int> ed(n);
        map<int,int> mp;
        for (int i=0;i<n;i++) cin >> st[i];
        for (int i=0;i<n;i++){
            cin >> ed[i];
            mp[ed[i]] = i;
        }
        while (st != ed){
            if (mp[st.back()]<n){
                if (ed[mp[st.back()]+1]==st[0]){
                    cout << 1;
                    st.push_back(st[0]);
                    st.erase(st.begin());
                } else if (ed[mp[st.back()]+1]==st[1]){
                    cout << 2;
                    st.push_back(st[1]);
                    st.erase(st.begin()+1);
                } else{
                    cout << 1;
                    st.push_back(st[0]);
                    st.erase(st.begin());
                }
            } else{
                cout << 1;
                st.push_back(st[0]);
                st.erase(st.begin());
            }
        }
        cout << '\n';
    }
}