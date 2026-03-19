#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n,m;
void swap_row(vector<vector<int>>&mat,int x){
    for (int i=1;i<=m/2;i++){
        swap(mat[x][i],mat[x][m+1-i]);
    }
}
void swap_cal(vector<vector<int>>&mat,int x){
    for (int i=1;i<=n/2;i++){
        swap(mat[i][x],mat[n+1-i][x]);
    }
}
int main(){
    cin >> n >> m;
    vector<vector<int>> mat(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    vector<pair<int,int>> ans;
    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=m/2;j++){
            string Case = "";
            Case.push_back(mat[i][j]==max(j,m+1-j)?'1':'0');
            Case.push_back(mat[i][m+1-j]==max(j,m+1-j)?'1':'0');
            Case.push_back(mat[n+1-i][j]==max(j,m+1-j)?'1':'0');
            Case.push_back(mat[n+1-i][m+1-j]==max(j,m+1-j)?'1':'0');
            if (Case == "0011"){
                swap_row(mat,n+1-i);
                swap_cal(mat,m+1-j);
                swap_row(mat,n+1-i);
                ans.push_back({0,n+1-i});
                ans.push_back({1,m+1-j});
                ans.push_back({0,n+1-i});
            } else if (Case == "0110"){
                swap_cal(mat,m+1-j);
                swap_row(mat,n+1-i);
                swap_cal(mat,m+1-j);
                swap_row(mat,n+1-i);
                ans.push_back({1,m+1-j});
                ans.push_back({0,n+1-i});
                ans.push_back({1,m+1-j});
                ans.push_back({0,n+1-i});
            } else if (Case == "1001"){
                swap_cal(mat,m+1-j);
                swap_row(mat,i);
                swap_cal(mat,m+1-j);
                swap_row(mat,i);
                ans.push_back({1,m+1-j});
                ans.push_back({0,i});
                ans.push_back({1,m+1-j});
                ans.push_back({0,i});
            } else if (Case == "1010"){
                swap_row(mat,n+1-i);
                swap_cal(mat,m+1-j);
                swap_cal(mat,j);
                swap_row(mat,n+1-i);
                ans.push_back({0,n+1-i});
                ans.push_back({1,m+1-j});
                ans.push_back({1,j});
                ans.push_back({0,n+1-i});
            } else if (Case == "1100"){
                swap_row(mat,i);
                swap_cal(mat,m+1-j);
                swap_row(mat,i);
                ans.push_back({0,i});
                ans.push_back({1,m+1-j});
                ans.push_back({0,i});
            }
        }
    }
    int ok = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mat[i][j] != j){
                ok = 0;
            }
        }
    }
    if (!ok){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (int i=0;i<int(ans.size());i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
}