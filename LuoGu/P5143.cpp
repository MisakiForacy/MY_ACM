#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef double llf;
struct info{
    i64 x,y,z;
};
bool cmp(const info &a,const info &b){
    return a.z < b.z;
}
vector<info>l;
i64 n,i,j;
llf s;
int main(){
    cin >> n;
    l.resize(n);
    for(i=0;i<n;i++){
        cin >> l[i].x >> l[i].y >> l[i].z;
    }
    sort(l.begin(),l.end(),cmp);
    for(i=1;i<n;i++){
        s += sqrt(pow((l[i].x-l[i-1].x),2)+pow((l[i].y-l[i-1].y),2)+pow((l[i].z-l[i-1].z),2));
    }
    cout << fixed << setprecision(3) << s << endl;
    return 0;
}