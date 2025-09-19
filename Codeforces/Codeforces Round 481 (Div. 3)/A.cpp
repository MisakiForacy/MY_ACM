#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using LL = long long;
int main(){
    int T = 1;
    // cin >> T;
    while (T --){
        int n,x;
        cin >> n;
        vector<int> a;
        int cnt = 0;
        for (int i = 1;i <= n;i ++){
            cin >> x;
            if (find(all(a),x) != a.end()){
                a[find(all(a),x) - a.begin()] = -1;
                a.push_back(x);
            } else{
                a.push_back(x);
                cnt ++;
            }
        }
        cout << cnt << '\n';
        for (int i = 0;i < n;i ++){
            if (a[i] != -1){
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
    }
}