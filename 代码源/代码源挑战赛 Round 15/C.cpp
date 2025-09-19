#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

struct node{
    int a, t, id;
    bool operator < (const node &that) const {
        return that.a > a;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<node> a(n);
    vector<int> ans;
    for (int i = 0;i < n;i ++){
        cin >> a[i].a >> a[i].t;
        a[i].id = i + 1;
    }
    sort(all(a));
    int now = 0;
    for (int i = 0;i < n;i ++){
        if (a[i].a >= now){
            now = a[i].a + a[i].t;
        } else{
            ans.push_back(a[i].id);
        }
    }
    if (siz(ans) == 0){
        cout << "Perfect\n";
        return;
    }
    sort(all(ans));
    for (auto x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}

int main(){
    int T = 1;
    // cin >> T;
    while (T --) solve();
}