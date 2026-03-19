#include <bits/stdc++.h>
using namespace std;
const int N = 500;
struct haha{
    int now,step;
};
int var[N];
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int>st(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> st[i];
    }
    queue<haha>Q;
    Q.push({a,0});
    int ans = -1;
    var[a] = 1;
    while (!Q.empty()){
        int now = Q.front().now;
        int step = Q.front().step;
        Q.pop();
        // cout << now << ' ' << step << '\n';
        if (now == b){
            ans = step;
            break;
        }
        int down,up;
        down = now - st[now];
        up = now + st[now];
        if (down>=1 && !var[down]){
            Q.push({down,step+1});
            var[down] = 1;
        }
        if (up<=n && !var[up]){
            Q.push({up,step+1});
            var[up] = 1;
        }
    }
    cout << ans << '\n';
}