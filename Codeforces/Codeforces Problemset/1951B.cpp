#include <bits/stdc++.h>
using namespace std;
int count(int k,int idx,vector<int>a){
    int cnt = 0;
    for (int i=idx+1;i<int(a.size());i++){
        if (a[i] < k){
            cnt ++;
        } else{
            return cnt;
        }
    }
    return cnt;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<int>a(n+1);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        int idx;
        for (int i=1;i<=n;i++){
            if (a[i] > a[k]){
                idx = i;
                break;
            }
        }
        int ans = 0;
        if  (idx < k){
            if (idx!=1){
                vector<int>b(a.begin(),a.end());
                vector<int>c(a.begin(),a.end());
                swap(b[1],b[k]);
                swap(c[idx],c[k]);
                ans = max(count(a[k],1,b),1+count(a[k],idx,c));
            } else{
                vector<int>b(a.begin(),a.end());
                swap(b[1],b[k]);
                ans = count(a[k],1,b);
            }
        } else{
            vector<int>b(a.begin(),a.end());
            swap(b[1],b[k]);
            ans = count(a[k],1,b);
        }
        cout << ans << '\n';
    }
}