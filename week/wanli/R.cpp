#include <bits/stdc++.h>
#define PI 3.14
#define endl '\n'
using namespace std;
typedef double db;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    db r,n,s1,s2,s;
    cin >> t;
    vector<int>res;
    for(int i=0;i<t;i++){
        cin >> r >> n >> s1;
        if(n == 6)cin >> s2;
        s = PI * r * r;
        if(n == 1)res.push_back(int(s * 3));
        else if(n == 2)res.push_back(int(s * 3 - s1));
        else if(n == 3)res.push_back(int(s * 3 - s1 * 2));
        else if(n == 4)res.push_back(int(s * 2));
        else if(n == 5)res.push_back(int(s));
        else if(n == 6)res.push_back(int(s * 3 - s1 * 3 + s2));
        else if(n == 7)res.push_back(int(s * 2 - s1));
    }
    for(int i=1;i<=t;i++){
        cout << "#Case" << i << " : " << res[i-1] << endl;
    }
}