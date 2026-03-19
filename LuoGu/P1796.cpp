#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
int main(){
    int n;
    cin >> n;
    vector<LL> lst = {0,0};
    for (int i=0;i<n;i++){
        int k;
        cin >> k;
        vector<LL> s(k+1,inf);
        for (int j=1;j<=k;j++){
            int idx,x;
            while (cin >> idx){
                if (!idx) break;
                cin >> x;
                s[j] = min(s[j],lst[idx]+x);
            }
        }
        lst = s;
    }
    LL ans = LLONG_MAX;
    for (int i=1;i<lst.size();i++){
        ans = min(ans,lst[i]);
    }
    cout << ans << '\n';
}