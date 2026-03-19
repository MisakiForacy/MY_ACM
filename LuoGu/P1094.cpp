#include <bits/stdc++.h>
using namespace std;
int main(){
    int w,n,cnt = 0;
    cin >> w >> n;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        if (a[i]>0){
            for (int j=n-1;j>i;j--){
                if (a[j]>0&&a[i]+a[j]<=w){
                    a[j] = -1;
                    break;
                }
            }
            cnt ++;
        }
    }
    cout << cnt << '\n';
}