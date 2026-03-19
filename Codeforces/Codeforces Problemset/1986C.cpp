#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,r,l,idx;
        string s,c;
        cin >> n >> m;
        vector<int>ind(m);
        vector<char>ca(m);
        vector<char>cc(m);
        vector<char>ans(n);
        cin >> s;
        for (int i=0;i<m;i++){
            cin >> ind[i];
        }
        cin >> c;
        for (int i=0;i<m;i++){
            ca[i] = c[i];
        }
        sort(ind.begin(),ind.end());
        sort(ca.begin(),ca.end());
        l = 0, r = m - 1, idx = 0;
        while (l <= r){
            if (idx+1!=m&&ind[idx]==ind[idx+1]){
                cc[idx] = ca[r];
                r --;
            } else{
                cc[idx] = ca[l];
                l ++;
            }
            idx ++;
        }
        for (int i=0;i<n;i++){
            ans[i] = s[i];
        }
        for (int i=0;i<m;i++){
            ans[ind[i]-1] = cc[i];
        }
        for (int i=0;i<n;i++){
            cout << ans[i];
        }
        cout << '\n';
    }
}