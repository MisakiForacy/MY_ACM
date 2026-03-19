#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int pos = 0, cnt = 0;
    for (int k = 1;k <= n;k++){
        while (pos < n && a[pos]<k) pos ++;
        if (pos < n && a[pos]>=k){
            cnt ++;
            pos ++;
        }
        if (pos == n) break;
    }
    cout << cnt << '\n';
}