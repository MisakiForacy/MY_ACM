#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m,k,x,q,q1,q2,res;
    cin >> n >> m;
    vector<vector<int>>List(n);
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> x;
            List[i].push_back(x);
        }
    }
    cin >> q;
    for(int i=0;i<q;i++){
        res = 0;
        cin >> q1 >> q2;
        for(int j=0;j<n;j++){
            if(find(List[j].begin(),List[j].end(),q1)!=List[j].end() && find(List[j].begin(),List[j].end(),q2)!=List[j].end()){
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}