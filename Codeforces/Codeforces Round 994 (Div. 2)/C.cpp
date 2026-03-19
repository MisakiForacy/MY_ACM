#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mex(vector<int> &a){
    sort(a.begin(),a.end());
    unique(a.begin(),a.end());
    int res = 0;
    for (int i=0;i<a.size();i++){
        if (res == a[i]){
            res ++;
        } else{
            return res;
        }
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> a(n+1,0);
        a[1] = 1;
        for (int i=2;i<=n;i++){
            a[i] = !a[i-1];
        }
        if (n&1){
            a[n] = 2;
        }
        if (abs(x-y) == 1 || abs(x-y) == n-1){
            for (int i=1;i<=n;i++){
                cout << a[i] << " \n"[i==n];
            }
        } else{
            vector<int> b;
            if ((y == n-1 || x == n-1) && n&1){
                swap(a[n],a[n-1]);
                goto xy;
            }
            b.push_back(a[x]);
            b.push_back(a[y-1 == 0 ? n : y-1]);
            b.push_back(a[y == n ? 1 : y+1]);
            a[y] = mex(b);
            xy:;
            for (int i=1;i<=n;i++){
                cout << a[i] << " \n"[i==n];
            }
        }
    }
}