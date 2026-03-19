#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll st,ed,len;
    bool operator < (const haha &that){
        if (that.st != st){
            return that.st > st;
        }
        return that.ed > ed;
    }
};
int main(){
    ll n;
    cin >> n;
    vector<haha> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].st >> a[i].ed;
        a[i].len = a[i].ed - a[i].st;
    }
    sort(a.begin(),a.end());
    ll len = a[0].len;
    for (int i=1;i<n;i++){
        if (a[i].st<a[i-1].ed && a[i].ed>=a[i-1].ed){
            len += a[i].len - (a[i-1].ed-a[i].st);
        } else if (a[i].st >= a[i-1].ed){
            len += a[i].len;
        }
        a[i].ed = max(a[i].ed,a[i-1].ed);
    }
    cout << len << '\n';
}