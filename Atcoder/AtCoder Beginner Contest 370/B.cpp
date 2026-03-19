#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n+1,vector<int>(n+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cin >> mp[i][j];
        }
    }
    int now = 1;
    for (int i=1;i<=n;i++){
        now = mp[max(now,i)][min(now,i)];
    }
    cout << now << '\n';
}