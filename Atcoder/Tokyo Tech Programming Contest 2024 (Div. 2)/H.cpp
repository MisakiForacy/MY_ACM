#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e8;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n+1,0);
    vector<int> id(5,0);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=4;i++) cin >> id[i];
    string ss = "TTPC";
    int t = 5;
    int cnt = 0;
    int p,ans;
    ans = p = 0;
    while (t --){
        for (int i=1;i<=6250000;i++){
            p ++;
            id[1] = a[id[1]], id[2] = a[id[2]];
            id[3] = a[id[3]], id[4] = a[id[4]];
            ss = "";
            ss.push_back(s[id[1]]);
            ss.push_back(s[id[2]]);
            ss.push_back(s[id[3]]);
            ss.push_back(s[id[4]]);
            if (ss == "TTPC"){
                cnt ++;
                ans = p;
                break;
            }
        }
    }
    if (cnt != 5){
        cout << ans << '\n';
    } else{
        cout << "NeverEnds\n";
    }
}