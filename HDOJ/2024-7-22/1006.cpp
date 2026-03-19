#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
double div(int a,int b){
    return 1.0 * a / b;
}
pair<int,int> update(pair<int,int>p1,pair<int,int>p2){
    double n1 = 1.0 * p1.first / p1.second;
    double n2 = 1.0 * p2.first / p2.second;
    if (n1 > n2){
        return 
    }
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,n1,n2;
        map<int,queue<int>>mp;
        int p[N];
        for (int i=0;i<n-1;i++){
            cin >> n1 >> n2;
            mp[n1].push(n2);
            mp[n2].push(n1);
        }
        for (int i=1;i<=n;i++){
            cin >> p[i];
        }
        map<int,int>found;
        queue<pair<int,pair<int,int>>>Q;
        Q.push({1,{1,{15,p[1]}}});
        while (!Q.empty()){
            int now = Q.front().first;
            found[now] = 1;
            ll m1 = Q.front().second.first;
            ll m2 = Q.front().second.second;
            if (div(m1,m2))
            while (!mp[now].empty()){
                if (!found[mp[now].front()]){
                    Q.push(mp[now].front());
                }
                mp[now].push();
            }
        }
    }
}