#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int>a,vector<int>b){
    return a[0] < b[0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a1(n,vector<int>(m));
        vector<vector<int>> a2(m,vector<int>(n));
        vector<vector<int>> b1(n,vector<int>(m));
        vector<vector<int>> b2(m,vector<int>(n)); 
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >> a1[i][j];
                a2[j][i] = a1[i][j];
            }
            sort(a1[i].begin(),a1[i].end());
        }
        for (int j=0;j<m;j++){
            sort(a2[j].begin(),a2[j].end());
        }
        sort(a1.begin(),a1.end(),cmp);
        sort(a2.begin(),a2.end(),cmp);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >> b1[i][j];
                b2[j][i] = b1[i][j];
            }
            sort(b1[i].begin(),b1[i].end());
        }
        for (int j=0;j<m;j++){
            sort(b2[j].begin(),b2[j].end());
        }
        sort(b1.begin(),b1.end(),cmp);
        sort(b2.begin(),b2.end(),cmp);
        cout << ((a1==b1 && a2==b2)?"YES\n":"NO\n");
    }
}