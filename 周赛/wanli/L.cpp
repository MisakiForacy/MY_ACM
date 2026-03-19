#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
static inline void print(vector<vector<int>>matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            printf("%4d",matrix[i][j]);
        }
        cout << endl;
    }
}
int main(){
    int t,n,num,x,y,k;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        num = 2, k = 0;
        x = n - 1, y = 0;
        matrix[y][x] = 1;
        while(num<=n*n){
            k = k % 4;
            if((0<=x+dx[k]&&x+dx[k]<=n-1) && (0<=y+dy[k]&&y+dy[k]<=n-1) && matrix[y+dy[k]][x+dx[k]]==0){
                matrix[y+dy[k]][x+dx[k]] = num;
                num++;
                x = x + dx[k], y = y + dy[k];
                if((k == 3 || k == 1) && x == n-1)k++;
            }
            else k++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%4d",matrix[i][j]);
            }
            cout << endl;
        }
    }
}