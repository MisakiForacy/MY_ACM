#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
#define INF 0x3f3f3f3f
#define PT 3.141592
#define e 2.718281
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n;
    string l;
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;
    bool flag4 = true;
    bool flag5 = true;
    bool flag5_1 = true;
    bool flag5_2 = true;
    bool flag5_3 = true;
    bool flag6 = true;
    cin >> n;
    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<char>>b(n,vector<char>(n));
    vector<vector<char>>c(n,vector<char>(n));
    for(int i=0;i<n;i++){
        cin >> l;
        for(int j=0;j<n;j++){
            a[i][j] = l[j];
        }
    }
    for(int i=0;i<n;i++){
        cin >> l;
        for(int j=0;j<n;j++){
            b[i][j] = l[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[j][n-i-1])flag1 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[n-i-1][n-j-1])flag2 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[n-j-1][i])flag3 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[i][n-j-1])flag4 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][n-j-1] = a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j] != b[j][n-i-1])flag5_1 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j] != b[n-i-1][n-j-1])flag5_2 = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j] != b[n-j-1][i])flag5_3 = false;
        }
    }
    flag5 = flag5_1|flag5_2|flag5_3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[i][j])flag6 = false;
        }
    }
    if(flag1)cout << 1;
    else if(flag2)cout << 2;
    else if(flag3)cout << 3;
    else if(flag4)cout << 4;
    else if(flag5)cout << 5;
    else if(flag6)cout << 6;
    else cout << 7;
    return 0;
}