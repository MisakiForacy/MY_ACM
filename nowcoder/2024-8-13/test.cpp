#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int idx = upper_bound(a.begin(),a.end(),k) - a.begin();
    int cnt = 0;
    for (int i=idx+1;i<n;i++){
        int t = a[i];
        while (t > a[idx]){
            t /= k;
            cnt ++;
        }
    }
    cout << a[idx] + cnt << '\n';
}