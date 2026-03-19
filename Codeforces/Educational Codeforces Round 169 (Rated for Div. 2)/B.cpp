#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int l,r,L,R;
        cin >> l >> r >> L >> R;
        int st = min(l,L);
        int ed = max(r,R);
        int cnt = 0;
        for (int i=st;i<=ed;i++){
            if (l<=i&&i<=r && L<=(i+1)&&(i+1)<=R){
                cnt ++;
            } else if (l<=(i+1)&&(i+1)<=r && L<=i&&i<=R){
                cnt ++;
            }
        }
        if (!cnt) cnt = 1;
        cout << cnt << '\n';
    }
}