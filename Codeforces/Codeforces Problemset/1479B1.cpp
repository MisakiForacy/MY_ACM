#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    map<int,queue<int>> mp;
    vector<int> a(n+1,0);
    int x,y;
    x = y = -1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]].push(i);
    }
    int cnt = 0;
    for (int i=1;i<=n;i++){
        mp[a[i]].pop();
        if (a[i] == x && a[i] == y) continue;
        else if (a[i] == x && a[i] != y){
            y = a[i];
        } else if (a[i] != x && a[i] == y){
            x = a[i];
        } else{
            if (!mp[x].size() && !mp[y].size()){
                x = a[i];
            } else if (mp[x].size() && mp[y].size()){
                if (mp[x].front() < mp[y].front()){
                    x = a[i];
                } else{
                    y = a[i];
                }
            } else if (mp[x].size()){
                x = a[i];
            } else{
                y = a[i];
            }
        }
        cnt ++;
    }
    cout << cnt << '\n';
}