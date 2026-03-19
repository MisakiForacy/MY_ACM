#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,x,b=0;
    cin >> n;
    vector<vector<int>>matrix(n,vector<int>(n));
    cin >> x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!x && i*j!=(n-1)*(n-1)){
                cin >> x;
                b^=1;
            }
            matrix[i][j] = b;
            x--;

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}