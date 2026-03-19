#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,sum = 0, cnt = 0;
    cin >> n >> m;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        if (sum + a[i] <= m){
            sum += a[i];
            cnt ++;
        } else {
            break;
        }
    }
    cout << cnt << '\n';
}