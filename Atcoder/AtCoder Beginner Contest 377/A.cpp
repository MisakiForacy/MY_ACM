#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {-1,1,2,2,1,-1,-2,-2};
const int dy[] = {-2,-2,-1,1,2,2,1,-1};
LL n,m;
bool check(int x,int y){
    if (1<=x&&x<=n && 1<=y&&y<=n){
        return 1;
    }
    return 0;
}
int main(){
    LL x,y;
    cin >> n >> m;
    set<pair<int,int>> st;
    for (int i=0;i<m;i++){
        cin >> x >> y;
        st.insert({x,y});
        for (int k=0;k<8;k++){
            if (check(x+dx[k],y+dy[k])){
                st.insert({x+dx[k],y+dy[k]});
            }
        }
    }
    cout << n*n - st.size() << '\n';
}