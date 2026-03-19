#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>a){
    int sum = 0;
    for (int i=0;i<int(a.size());i++){
        sum += a[i];
    }
    return (!sum);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>ans;
        for (int i=0;i<n;i++) cin >> a[i];
        int t;
        for (t=0;t<=40;t++){
            if (check(a)) break;
            sort(a.begin(),a.end());
            int x = (a[0] + a.back()) / 2;
            for (int i=0;i<n;i++){
                a[i] = abs(a[i] - x);
            }
            ans.push_back(x);
        }
        if (t <= 40){
            cout << t << '\n';
            for (int i=0;i<t;i++){
                cout << ans[i] << " \n"[i==int(ans.size())-1];
            }
            if (!t) cout << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}