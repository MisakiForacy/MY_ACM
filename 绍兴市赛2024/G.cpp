#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 998244353;
vector<vector<LL>> Cal(int n){
    vector<vector<LL>> C(n+1,vector<LL>(n+1,0));
    C[1][1] = 1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=n;j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    return C;
}
int main(){
    int n,x;
    cin >> n;
    set<int> st;
    for (int i=0;i<n;i++){
        cin >> x;
        for (int j=1;j*j<=x;j++){
            if (x % j == 0){
                st.insert(j);
                st.insert(x/j);
            }
        }
    }
    LL ans = 1;
    vector<vector<LL>> C = Cal(st.size()-1);
    for (int i=1;i<st.size();i++){
        ans += C[st.size()-1][i];
        ans %= MOD;
        cout << C[st.size()-1][i] << '\n';
    }
    cout << ans << '\n';
}