#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
const char x0[] = { 'X','X','X','X','.','X','X','.','X','X','.','X','X','X','X',
                    '.','.','X','.','.','X','.','.','X','.','.','X','.','.','X',
                    'X','X','X','.','.','X','X','X','X','X','.','.','X','X','X',
                    'X','X','X','.','.','X','X','X','X','.','.','X','X','X','X',
                    'X','.','X','X','.','X','X','X','X','.','.','X','.','.','X',
                    'X','X','X','X','.','.','X','X','X','.','.','X','X','X','X',
                    'X','X','X','X','.','.','X','X','X','X','.','X','X','X','X',
                    'X','X','X','.','.','X','.','.','X','.','.','X','.','.','X',
                    'X','X','X','X','.','X','X','X','X','X','.','X','X','X','X',
                    'X','X','X','X','.','X','X','X','X','.','.','X','X','X','X'};
int main(){
    int n,z=0;
    string x;
    cin >> n;
    cin >> x;
    vector<vector<char>>screen(5,vector<char>(4*n-1,'.'));
    for(int t=0;t<n;t++){
        z = 0;
        for(int i=0;i<5;i++){
            for(int j=t*4;j<t*4+3;j++){    
                screen[i][j] = x0[(x[t]-'0')*15+z];
                z++;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<n*4-1;j++){
            cout << screen[i][j];
        }
        cout << endl;
    }
    return 0;
}