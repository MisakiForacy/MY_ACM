#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        int x,y,z,k;
        x = y = z = k = 0;
        for (int i=0;i<n;i++){
            if (s2[i]==s3[i]&&s1[i]!=s2[i]){
                x ++;
            } else if (s1[i]==s3[i]&&s1[i]!=s2[i]){
                y ++;
            } else if (s1[i]==s2[i]&&s2[i]!=s3[i]){
                z ++;
            } else{
                k ++;
            }
        }
        int d1,d2,d3;
        d1 = y + z, d2 = x + z, d3 = x + y;
        int mi = min({d1,d2,d3});
        int mx = max({d1,d2,d3});
        int ans = (mi + mx) / 2;
        cout << ans + k << '\n';
    }
}