#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,c,cnt,a;
    cin >> n >> c;
    cin >> a;
    int ls = a;
    cnt = 1;
    for (int i=1;i<n;i++){
        cin >> a;
        if (a - ls >= c){
            ls = a;
            cnt ++;
        }
    }
    cout << cnt << '\n';
}