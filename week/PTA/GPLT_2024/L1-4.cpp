#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,s = 0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x;
        s += x;
    }
    cout << ((s-(m-1)*n)>0?(s-(m-1)*n):0) << endl;
    return 0;
}