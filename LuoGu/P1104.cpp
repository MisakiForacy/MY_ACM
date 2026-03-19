#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef double llf;
struct info{
    string name;
    i64 y,m,d;
    i64 level;
};
vector<info>s;
i64 n,i,j,y,m,d;
string name;
bool cmp(const info &a,const info &b){
    if(a.y != b.y)return a.y < b.y;
    else if(a.m != b.m)return a.m < b.m;
    else if(a.d != b.d)return a.d < b.d;
    return a.level > b.level;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    s.resize(n);
    for(i=0;i<n;i++){
        cin >> s[i].name >> s[i].y >> s[i].m >> s[i].d;
        s[i].level = i;
        // s.insert(s.begin(),{name,y,m,d});
    }
    sort(s.begin(),s.end(),cmp);
    for(i=0;i<n;i++){
        cout << s[i].name << endl;
    }
    return 0;
}