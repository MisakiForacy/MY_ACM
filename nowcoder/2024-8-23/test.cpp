#include <bits/stdc++.h>
using namespace std;
int s[40000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> st;
        for (int i=0;i<n*15;i++) s[i] = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (a[i] < 15*n && !s[a[i]]){
                for (int j=1;j*a[i]<15*n;j++){
                    s[j*a[i]] = 1;
                }
            }
        }
        for (int i=2;i<15*n;i++){
            if (!s[i]){
                cout << i << '\n';
                break;
            }
        }
    }
}