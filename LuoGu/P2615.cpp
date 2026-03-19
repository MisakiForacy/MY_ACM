#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int N,lx,ly;
    cin >> N;
    vector<vector<int>>a(N,vector<int>(N,0));
    a[0][N/2] = 1;
    lx = N/2;ly = 0;
    for(int k=2;k<=N*N;k++){
        if((lx!=N-1)&(ly==0)){
            a[N-1][lx+1] = k;
            lx = lx+1;ly = N-1;
        }
        else if((lx==N-1)&(ly!=0)){
            a[ly-1][0] = k;
            lx = 0;ly = ly-1;
        }
        else if((lx==N-1)&(ly==0)){
            a[ly+1][N-1] = k;
            lx = N-1;ly = ly+1;
        }
        else if((ly!=0)&(lx!=N-1)){
            if(a[ly-1][lx+1]==0){
                a[ly-1][lx+1] = k;
                lx = lx+1;ly = ly-1;
            }
            else{
                a[ly+1][lx] = k;
                lx = lx;ly = ly+1;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}