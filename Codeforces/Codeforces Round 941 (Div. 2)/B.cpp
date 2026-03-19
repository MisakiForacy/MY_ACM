#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define N 1005
#define INF 0x3f3f3f3f
#define PI 3.1415926
typedef long long ll;
typedef double db;
using namespace std;

bool f1,f2,f3,f4,flag;
int n,m,i,j,k,t;
int a[N], b[N][N];
string line;
static vector<vector<char>>matrix(505,vector<char>(505));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        f1 = f2 = f3 = f4 = flag = false;
        cin >> n >> m;
        for(i=0;i<n;i++){
            cin >> line;
            for(j=0;j<m;j++){
                matrix[i][j] = line[j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(matrix[i][j]!=matrix[0][0]){
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)cout << "YES" << endl;
        else if(n==1 && m==1){
            cout << "YES" << endl;
        }
        else{
            for(i=1;i<m;i++){
                if(matrix[0][0]!=matrix[0][i])f1 = true;
                if(matrix[n-1][0]!=matrix[n-1][i])f2 = true;
            }
            for(j=1;j<n;j++){
                if(matrix[0][0]!=matrix[j][0])f3 = true;
                if(matrix[0][m-1]!=matrix[j][m-1])f4 = true;
            }
            if(!f1 && !f2 && f3 && f4){
                if(matrix[0][0]==matrix[n-1][0])cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if(f1 && f2 && !f3 && !f4){
                if(matrix[0][0]==matrix[0][m-1])cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if(f1+f2+f3+f4>=2)cout << "YES" << endl;
            else if(f1+f2+f3+f4==0 || f1+f2+f3+f4==1 && matrix[0][0]==matrix[n-1][m-1])cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}