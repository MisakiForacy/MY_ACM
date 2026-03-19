#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
vector<string>a1,a2;
i64 n,p,i,j,x,cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> p;
    a1.resize(n), a2.resize(p);
    for(i=0;i<n;i++){
        cin >> a1[i];
        reverse(a1[i].begin(),a1[i].end());
    }
    for(i=0;i<p;i++){
        cnt = 0;
        cin >> x >> a2[i];
        reverse(a2[i].begin(),a2[i].end());
        for(j=0;j<n;j++){
            if(a1[j].find(a2[i])==0)cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}