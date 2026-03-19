#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,m;
    cin >> n >> m;
    set<vector<int>> st;
    for (int i=0;i<m;i++){
        vector<int> tmp(n);
        for (int j=0;j<n;j++){
            cin >> tmp[j];
        }
        vector<int> nuw(n);
        queue<vector<int>> tmp_st;
        for (auto k:st){
            for (int j=0;j<n;j++){
                nuw[j] = k[tmp[j]-1];
            }
            tmp_st.push(nuw);
        }
        while (!tmp_st.empty()){
            st.insert(tmp_st.front());
            tmp_st.pop();
        }
        st.insert(tmp);
    }
    // cout << '\n';
    // for (auto k:st){
    //     for (int i=0;i<k.size();i++){
    //         cout << k[i] << " \n"[i==k.size()-1];
    //     }
    // }
    cout << st.size() << '\n';
}