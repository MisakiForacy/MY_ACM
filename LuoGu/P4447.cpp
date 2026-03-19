#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main(){
    int n,mi = inf;
    cin >> n;
    vector<int>a(n);
    map<int,int> mp;
    for (int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]] ++;
    }
    vector<int>q;
    for (auto c:mp){
        for (int i=0;i<c.second;i++){
            int now = c.first;
            q.push_back(now);
            while (mp.count(++now)){
                q.push_back(now);
                mp[now] --;
            }
            mi = min(mi,int(q.size()));
            q.clear();
        }
    }
    cout << mi << '\n';
}