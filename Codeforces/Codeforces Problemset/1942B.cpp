#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans;
        int mex = 0;
        vector<int> m(n+1,0);
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (a[i] >= 0){
                ans.push_back(mex);
            } else{
                ans.push_back(mex-a[i]);
            }
            m[ans.back()] = 1;
            while (m[mex]) mex ++;
        }
        for (int i=0;i<n;i++){
            cout << ans[i] << " \n"[i==n-1];
        }
    }
}