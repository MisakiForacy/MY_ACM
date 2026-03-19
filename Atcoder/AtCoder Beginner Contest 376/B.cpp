#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,q,s;
    char c;
    cin >> n >> q;
    int l = 0, r = 1;
    int cnt = 0;
    vector<int> a(n);
    iota(a.begin(),a.end(),1);
    for (int i=0;i<q;i++){
        cin >> c >> s;
        int st = 0;
        int ok = 1;
        if (c == 'R'){
            while (a[r]!=s){
                r ++;
                r %= n;
                st ++;
                if (r == l){
                    ok = 0;
                }
            }
        } else{
            while (a[l]!=s){
                l ++;
                l %= n;
                st ++;
                if (r == l){
                    ok = 0;
                }
            }
        }
        if (!ok){
            cnt += n - st;
        } else{
            cnt += st;
        }
    }
    cout << cnt << '\n';
}