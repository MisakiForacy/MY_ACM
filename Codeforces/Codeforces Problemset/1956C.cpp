#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll sum = 0, times;
        for (int i=1;i<=n;i++){
            sum += i * (2 * i - 1);
        }
        times = 2 * n;
        cout << sum << ' ' << times << '\n';
        int line = 2 * n + 1;
        for (int i=0;i<times;i++){
            cout << ((i&1)?1:2) << ' ';
            cout << line / 2 << ' ';
            line --;
            for (int i=1;i<=n;i++){
                cout << i << " \n"[i==n];
            }
        }
    }
}