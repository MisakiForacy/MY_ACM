#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M,N,nn;
    cin >> M >> N;
    vector<int>num(10,0);
    for(int n=M;n<=N;n++){
        nn = n;
        while(nn!=0){
            num[nn%10]++;
            nn/=10;
        }
    }
    for(vector<int>::iterator it=num.begin();it!=num.end();it++){
        cout << *it << " ";
    }
    return 0;
}