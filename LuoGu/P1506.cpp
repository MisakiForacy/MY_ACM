#include <bits/stdc++.h>
using namespace std;
struct haha{
    int x,y;
};
int main(){
    int n,m;
    string s;
    cin >> n >> m;
    vector<vector<int>>mat(n+1,vector<int>(m+1));
    for (int i=1;i<=n;i++){
        cin >> s;
        for (int j=0;j<m;j++){
            mat[i][j+1] = (s[j]=='*');
        }
    }
    queue<haha>Q;
    while (!Q.empty()){
        
    }
}