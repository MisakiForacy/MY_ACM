#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
using namespace std;
typedef long long i64;
typedef double llf;
struct info{
    string num;
};
bool cmp(const info &a,const info &b){
    return a.num+b.num > b.num+a.num;
}
vector<info>l;
int maxn = -1;
string num;
i64 n,i,j;
int main(){
    cin >> n;
    l.resize(n);
    for(i=0;i<n;i++){
        cin >> l[i].num;
    }
    sort(l.begin(),l.end(),cmp);
    for(i=0;i<n;i++){
        cout << l[i].num;
    }
    cout << endl;
    return 0;
}