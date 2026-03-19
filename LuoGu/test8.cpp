#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

int dp(vector<int> p,int n){
    if(n==0)return 0;
    int q = -INF;
    cout << "q:" << q << endl;
    for (int i=1;i<=n;i++){
        q = max(q,p[i-1]+dp(p,n-i));
    }
    return q;
}
int main(){
    cout <<(1+13+46+101+157+256+355+589+1401);
    vector<int>p;
    int n;
    cin >> n;
    p = {1,5,8,9,10,17,17,20,24,30};
    cout << dp(p,n);
}