#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<int> a(n,0);
    for (int i=0;i<n;i++){
        if (s[i]=='r'){
            a[i] = 1;
        } else if (s[i]=='b'){
            a[i] = 2;
        }
    }
    for (int i=1;i<n;i++){
        int idx = i-1;
        int left,right;
        left = right = 0;
        int f = 0, t = 1;
        while (idx!=i || (idx==i && t)){
            t = 0;
            if (f && a[idx] && a[idx]!=f){
                break;
            } else{
                left ++;
                if (a[idx]){
                    f = a[idx];
                }
            }
            idx = (idx-1+n) % n;
        }
        idx = i;
        f = 0, t = 1;
        while (idx!=i || (idx==i && t)){
            t = 0;
            if (f && a[idx] && a[idx]!=f){
                break;
            } else{
                right ++;
                if (a[idx]){
                    f = a[idx];
                }
            }
            idx = (idx+1) % n;
        }
        ans = max(ans,left + right);
    }
    ans = min(ans,n);
    cout << ans << '\n';
}