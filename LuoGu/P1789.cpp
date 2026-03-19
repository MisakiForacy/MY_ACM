#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,m,k,count=0;
    int x,y;
    int o,p;
    cin >> n >> m >> k;
    vector<vector<int>>square(n+4,vector<int>(n+4,1));
    while(m--){
        cin >> x >> y;
        x+=1;y+=1;
        square[y-1][x-1]=0;square[y-1][x]=0;square[y-1][x+1]=0;
        square[y][x-1]=0;square[y][x]=0;square[y][x+1]=0;
        square[y+1][x-1]=0;square[y+1][x]=0;square[y+1][x+1]=0;
        square[y-2][x]=0;square[y+2][x]=0;square[y][x-2]=0;square[y][x+2]=0;
    }
    while(k--){
        cin >> o >> p;
        o+=1;p+=1;
        square[o-2][p-2]=0;square[o-2][p-1]=0;square[o-2][p]=0;square[o-2][p+1]=0;square[o-2][p+2]=0;
        square[o-1][p-2]=0;square[o-1][p-1]=0;square[o-1][p]=0;square[o-1][p+1]=0;square[o-1][p+2]=0;
        square[o][p-2]=0;square[o][p-1]=0;square[o][p]=0;square[o][p+1]=0;square[o][p+2]=0;
        square[o+1][p-2]=0;square[o+1][p-1]=0;square[o+1][p]=0;square[o+1][p+1]=0;square[o+1][p+2]=0;
        square[o+2][p-2]=0;square[o+2][p-1]=0;square[o+2][p]=0;square[o+2][p+1]=0;square[o+2][p+2]=0;
    }
    for(int i=2;i<n+2;i++){
        for(int j=2;j<n+2;j++){
            count += square[i][j];
        }
    }
    cout << count;
}