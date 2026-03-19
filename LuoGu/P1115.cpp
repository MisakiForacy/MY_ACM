#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n,x,sum=0;
    int maxn = -INF;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        sum += x;
        if(sum > maxn)maxn = sum;
        if(sum < 0)sum = 0;
    }
    cout << maxn << endl;
    return 0;
}