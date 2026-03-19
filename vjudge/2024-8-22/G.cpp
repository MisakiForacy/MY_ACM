#include <bits/stdc++.h>
using namespace std;
int main(){
    int m;
    while (cin >> m){
        if (!m) break;
        int n = 0,mx = 0;
        vector<int> a(m);
        for (int i=0;i<m;i++){
            cin >> a[i];
            n ^= a[i];
        }
        int cnt = 0;
        for (int i=0;i<m;i++){
            if ((n^a[i])<a[i]){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}