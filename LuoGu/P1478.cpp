#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll x,y;
};
bool cmp(haha a,haha b){
    return a.y < b.y;
}
int main(){
    ll n,s,a,b,cnt = 0;
    cin >> n >> s >> a >> b;
    vector<haha>ap(n);
    for (int i=0;i<n;i++){
        cin >> ap[i].x >> ap[i].y;
    }
    sort(ap.begin(),ap.end(),cmp);
    for (auto app:ap){
        if (a+b>=app.x && s>=app.y){
            s -= app.y;
            cnt ++;
        }
    }
    cout << cnt << '\n';
}