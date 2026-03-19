#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll w,c,t;
    char id;
};

bool cmp(haha x,haha y){
    if (x.w != y.w){
        return x.w > y.w;
    }
    if (x.c != y.c){
        return x.c > y.c;
    }
    if (x.t != y.t){
        return x.t < y.t;
    }
}

int main(){
    vector<haha>a(2);
    cin >> a[0].w >> a[0].c >> a[0].t;
    cin >> a[1].w >> a[1].c >> a[1].t;
    a[0].id = 'A';
    a[1].id = 'B';
    sort(a.begin(),a.end(),cmp);
    cout << a[0].id << '\n';
}