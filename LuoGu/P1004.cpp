#include <bits/stdc++.h>
#define N 15
using namespace std;
int n;
int rec[N][N][N][N];
static vector<vector<int>>matrix, sign;
static inline int dfs(int x1,int y1,int x2,int y2);
int main(){
    int x,y,num;
    cin >> n;
    matrix.resize(n+2,vector<int>(n+2,0));
    sign.resize(n+2,vector<int>(n+2,1));
    for(int i=0;i<N;i++){
        for(int ii=0;ii<N;ii++){
            for(int iii=0;iii<N;iii++){
                for(int iiii=0;iiii<N;iiii++){
                    rec[i][ii][iii][iiii] = -1;
                }
            }
        }
    }
    for(int i=0;i<=n+1;i++){
        sign[0][i] = 0;
        sign[i][0] = 0;
        sign[i][n+1] = 0;
        sign[n+1][i] = 0;
    }
    cin >> y >> x >> num;
    matrix[y][x] = num;
    while(!(y==0 && x==0 && num==0)){
        cin >> y >> x >> num;
        matrix[y][x] = num;
    }
    cout  << dfs(1,1,1,1) << endl;
    return 0;
}
static inline int dfs(int x1,int y1,int x2,int y2){
    int sum = 0;
    if(x1==n&&y1==n&&x2==n&&y2==n){
        return matrix[n][n];
    }
    if(rec[y1][x1][y2][x2]!=-1)return rec[y1][x1][y2][x2];
    else if(!(sign[y1+1][x1])&&sign[y2+1][x2]&&sign[y2][x2+1])sum = max(dfs(x1+1,y1,x2,y2+1),dfs(x1+1,y1,x2+1,y2)) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else if(!(sign[y1][x1+1])&&sign[y2+1][x2]&&sign[y2][x2+1])sum = max(dfs(x1,y1+1,x2,y2+1),dfs(x1,y1+1,x2+1,y2)) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else if(!(sign[y2+1][x2])&&sign[y1+1][x1]&&sign[y1][x1+1])sum = max(dfs(x1,y1+1,x2+1,y2),dfs(x1+1,y1,x2+1,y2)) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else if(!(sign[y2][x2+1])&&sign[y1+1][x1]&&sign[y1][x1+1])sum = max(dfs(x1,y1+1,x2,y2+1),dfs(x1+1,y1,x2,y2+1)) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else if(!(sign[y1][x1+1])&&!(sign[y2][x2+1]))sum = dfs(x1,y1+1,x2,y2+1) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else if(!(sign[y1+1][x1])&&!(sign[y2][x2+1]))sum = dfs(x1+1,y1,x2,y2+1) + matrix[y1][x1] + matrix[y2][x2];
    else if(!(sign[y1][x1+1])&&!(sign[y2+1][x2]))sum = dfs(x1,y1+1,x2+1,y2) + matrix[y1][x1] + matrix[y2][x2];
    else if(!(sign[y1+1][x1])&&!(sign[y2+1][x2]))sum = dfs(x1+1,y1,x2+1,y2) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    else sum = max(max(dfs(x1,y1+1,x2,y2+1),dfs(x1+1,y1,x2,y2+1)),max(dfs(x1,y1+1,x2+1,y2),dfs(x1+1,y1,x2+1,y2))) + matrix[y1][x1] + (y1!=y2)*matrix[y2][x2];
    rec[y1][x1][y2][x2] = sum;
    return sum;
}
