#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 i,j,len,ope,clo;
string ss;
struct info{
    char s;
    i64 bal,idx;
};
static inline bool cmp(info &a,info &b){
    if(a.bal != b.bal)return a.bal < b.bal;
    return a.idx > b.idx;
}
vector<info>ll;
int main(){
    cin >> ss;
    len = ss.length();
    ll.resize(len+1);
    for(i=1;i<=len;i++){
        ll[i].s = ss[i-1];
        ll[i].bal = ope - clo;
        if(ss[i-1] == '(') ope ++;
        if(ss[i-1] == ')') clo ++;
        ll[i].idx = i;
    }
    sort(ll.begin()+1,ll.end(),cmp);
    for(i=1;i<=len;i++){
        cout << ll[i].s;
    }
    return 0;
}