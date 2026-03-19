#include <bits/stdc++.h>
using namespace std;
struct info{
    int id;
    double x,y,d;
};
bool cmp(info a,info b){
    if (a.d!=b.d) return a.d > b.d;
    return a.id < b.id;
}
int main(){
    int n,k,t,x,y,cnt = 0;
    cin >> n >> k >> t;
    vector<info>a(n);
    vector<pair<double,double>>b(k);
    for (int i=0;i<n;i++){
        a[i].id = i+1;
        cin >> a[i].x >> a[i].y;
    }
    for (int i=0;i<k;i++){
        cin >> b[i].first >> b[i].second;
    }
    for (int i=0;i<t;i++){
        cin >> x >> y;
        for (int i=0;i<n;i++){
            a[i].d = sqrt(pow(a[i].x-x,2)+pow(a[i].y-y,2));
        }
        sort(a.begin(),a.end(),cmp);
        // cout << a[0].x << ':' << a[0].y << ':' << a[0].d << '\n';
        if (find(b.begin(),b.end(),pair<double,double>{a[0].x,a[0].y})!=b.end()){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}