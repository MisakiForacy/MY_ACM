#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int dx[] = {-1,0,1,1,1,0,-1,-1};
const int dy[] = {-1,-1,-1,0,1,1,1,0};
int main(){
    int n,m,i,j;
    vector<char> map(1000000);
    vector<int> mm(1000000,0);
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>map[i*m*n+j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(map[i*m*n+j]=='*'){
                for(int k=0;k<8;k++)mm[(i+dy[k])*m*n+j+dx[k]] += 1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(map[i*m*n+j]=='?')cout<<mm[i*m*n+j];
            else cout<<map[i*m*n+j];
        }
        cout<<endl;
    }
    return 0;
}