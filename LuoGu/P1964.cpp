#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    struct node{
        LL a,b,c;
        string st;
    };
    LL m,n,a,b,c;
    cin >> m >> n;
    vector<node> obj;
    string st;
    for (int i=0;i<n;i++){
        cin >> a >> b >> c >> st;
        for (int j=0;j<i;j++){
            if (obj[j].st == st){
                if (obj[j].c-obj[j].a < a){
                    a -= obj[j].c - obj[j].a;
                    obj[j].a = obj[j].c;
                } else{
                    obj[j].a += a;
                    a = 0;
                    break;
                }
            }
        }
        if (a){
            obj.push_back({a,b,c,st});
        }
    }
    for (int i=0;i<obj.size();i++){
        if (obj[i].a>obj[i].c){
            obj.push_back({obj[i].c-obj[i].a,obj[i].b,obj[i].c,st});
            obj[i].a = obj[i].c;
        }
    }
    int siz = 21-m;
    vector<LL> dp(siz+1,0);
    for (int i=0;i<obj.size();i++){
        for (int j=siz;j>=1;j--){
            dp[j] = max(dp[j],dp[j-1]+obj[i].a*obj[i].b);
        }
    }
    cout << dp[siz] << '\n';
}