#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N (i64)(1e6+10)
#define endl '\n'
using namespace std;
typedef long long i64;
struct info{
    bool dir;
    string name;
};
vector<info>p;
i64 n,m,a,s,i,idx;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    p.resize(n);
    for(i=0;i<n;i++){
        cin >> p[i].dir >> p[i].name;
    }
    idx = 0;
    for(i=0;i<m;i++){
        cin >> a >> s;
        if(!(a^p[idx].dir)){
            idx -= s;
            if(idx < 0){
                idx = n + idx;
            }
        }
        else{
            idx += s;
            if(idx >= n){
                idx = idx - n;
            }
        }
    }
    cout << p[idx].name << endl;
}