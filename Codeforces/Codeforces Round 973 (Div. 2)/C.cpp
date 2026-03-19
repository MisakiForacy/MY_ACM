#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
bool ask(string t){
    cout << "? " << t << '\n';
    int x; cin >> x;
    return x;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string ans = (ask("1")?"1":"0");
        int l = 1,r = 1;
        while (ans.size()!=n){
            if (l){
                l = 0;
                if (ask('1'+ans)){
                    ans = '1'+ans;
                    l = 1;
                } else if (ask('0'+ans)){
                    ans = '0'+ans;
                    l = 1;
                }
            }else{
                if (ask(ans+'1')){
                    ans = ans+'1';
                } else{
                    ans = ans+'0';
                }
            }
        }
        cout << "! " << ans << '\n';
    }
}