#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n;
        string s;
        cin >> n;
        cin >> s;
        s = ' ' + s;
        LL ans = (1+n)*n / 2;
        deque<LL> dq;
        for (int i=n;i>=1;i--){
            if (s[i] == '1'){
                dq.push_back(i);
            } else if (!dq.empty()){
                ans -= dq.front();
                dq.pop_front();
            }
        }
        while (dq.size() >= 2){
            ans -= dq.front();
            dq.pop_back();
            dq.pop_front();
        }
        cout << ans << '\n';
    }
}