#include <bits/stdc++.h>
using namespace std;
struct info{
    int n,a,b,c,d;
};
bool cmp(info &a,info &b){
    if(a.d != b.d)return a.d > b.d;
    else if(a.a != b.a)return a.a > b.a;
    return a.n < b.n;
}
int main(){
    int n;
    cin >> n;
    struct info a[n];
    for(int i=1;i<=n;i++){
        cin >> a[i-1].a >> a[i-1].b >> a[i-1].c;
        a[i-1].n = i;
        a[i-1].d = a[i-1].a + a[i-1].b + a[i-1].c;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++){
        cout << a[i].n << " " << a[i].d << endl;
    }
    return 0;
}