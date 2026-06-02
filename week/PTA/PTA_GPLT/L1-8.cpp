#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int main(){
    int m,n,k,x,y;
    cin >> n >> m;
    vector<string>sign(n);
    vector<int>row(m);
    vector<int>search;
    vector<vector<int>>matrix(m,vector<int>(10));
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,sign[i]);
    }
    for(int i=0;i<m;i++){
        cin >> row[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<10;j++){
            cin >> matrix[i][j];
        }
    }
    cin >> k;
    search.resize(k);
    for(int i=0;i<k;i++){
        cin >> search[i];
    }
    for(int i=0;i<k;i++){
        int tmp = search[i]/10;
        // cout << tmp;
        if(find(row.begin(),row.end(),tmp)==row.end()){
            cout << "?" << endl;
            continue;
        }
        y = (find(row.begin(),row.end(),tmp)-row.begin());
        x = search[i] % 10;
        if(matrix[y][x]==-1){
            cout << "?" << endl;
            continue;
        }
        cout << sign[matrix[y][x]-1] << endl;
    }
}