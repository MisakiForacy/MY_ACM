#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 i,j,len,ope,clo;
string ss,ss1,ss2,ss3;
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
    ss1 = ss;
    if(ss == "()")cout << "()";
    while(ss!=ss2){
        ss3 = ss2;
        ss2 = "";
        for(i=1;i<=len;i++){
            ll[i].s = ss1[i-1];
            ll[i].bal = ope - clo;
            if(ss1[i-1] == '(') ope ++;
            if(ss1[i-1] == ')') clo ++;
            ll[i].idx = i;
        }
        sort(ll.begin()+1,ll.end(),cmp);
        for(i=1;i<=len;i++){
            ss2.push_back(ll[i].s);
        }
        ss1 = ss2;
        // cout << ss2 << endl;
    }
    cout << ss3;
    return 0;
}
// void Switch(){
//     ss2 = "";
//     ope = 0, clo = 0;
//     for(i=1;i<=len;i++){
//         ll[i].s = ss1[i-1];
//         ll[i].bal = ope - clo;
//         if(ss1[i-1] == '(') ope ++;
//         if(ss1[i-1] == ')') clo ++;
//         ll[i].idx = i;
//     }
//     sort(ll.begin()+1,ll.end(),cmp);
//     for(i=1;i<=len;i++){
//         ss2.push_back(ll[i].s);
//     }   
// }