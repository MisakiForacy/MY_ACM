#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int W,X,H,q,count=0;
    int x1,y1,z1,x2,y2,z2;
    cin >> W >> X >> H;
    cin >> q;
    vector<vector<vector<int>>>a(W,vector<vector<int>>(X,vector<int>(H,1)));
    while(q--){
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if(z1>z2)swap(z1,z2);
        for(int x=x1-1;x<x2;x++){
            for(int y=y1-1;y<y2;y++){
                for(int z=z1-1;z<z2;z++){
                    a[x][y][z] = 0;
                }
            }
        }
    }
    for(int x=0;x<W;x++){
        for(int y=0;y<X;y++){
            for(int z=0;z<H;z++){
                count += a[x][y][z];
            }
        }
    }
    cout << count;
    return 0;
}