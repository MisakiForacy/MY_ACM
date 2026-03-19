#include <bits/stdc++.h>
using namespace std;
struct info{
    string name;
    int s1,s2,s3;
    int total,id;
};
bool cmp(const info&a1,const info&a2){
    // if(a1.total==a2.total)return a1.id<a2.id;
    return a1.total>a2.total;
}
int main(){
    int n,i;
    cin >> n;
    vector<info>a(n);
    for(i=0;i<n;i++){
        cin >> a[i].name >> a[i].s1 >> a[i].s2 >> a[i].s3;
        a[i].total = a[i].s1 + a[i].s2 + a[i].s3;
        a[i].id = i;
    }
    sort(a.begin(),a.end(),cmp);
    cout << a[0].name << " " << a[0].s1 << " " << a[0].s2 << " " << a[0].s3;
}