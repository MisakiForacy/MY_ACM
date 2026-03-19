#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>>list(n+1,vector<int>(n+1,0));
    list[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i+1;j++){
            list[i][j] = list[i-1][j-1] + list[i-1][j];
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}