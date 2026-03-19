#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        string s;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> s;
            a[i] = s.length();
        }
        int cnt = 0;
        for (int i=0;i<n;i++){
            if (m-a[i]>=0){
                m -= a[i];
                cnt ++;
            } else{
                break;
            }
        }
        cout << cnt << '\n';
    }
}