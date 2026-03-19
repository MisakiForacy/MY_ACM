#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
int main(){
    int n,k,x,t=0;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> x;
        if (5-x>=k){
            t ++;
        }
    }
    cout << t/3 << '\n';
}