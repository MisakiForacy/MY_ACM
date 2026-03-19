#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
#define N 100000
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,count=0;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(3));
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    for(int i=1;i<n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        for(int j=0;j<i;j++){
            if(abs(a[i][0]-a[j][0])<=5&&abs(a[i][1]-a[j][1])<=5&&abs(a[i][2]-a[j][2])<=5&&abs(a[i][0]+a[i][1]+a[i][2]-a[j][0]-a[j][1]-a[j][2])<=10)count++;
        }
    }
    cout << count;
    return 0;
}