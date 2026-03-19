#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n,m;
struct haha{
    int x,y,t;
    bool operator < (const haha &that) const {
        return t < that.t;
    }
};
int Set[N];
vector<haha> a;
int findx(int x){
    if (Set[x] != x){
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void merge(int a,int b){
    Set[max(a,b)] = min(a,b);
}
void init(){
    for (int i=0;i<=n;i++){
        Set[i] = i;
    }
}
bool check(int mid){
    init();
    for (int i=0;i<mid;i++){
        merge(findx(a[i].x),findx(a[i].y));
    }
    for (int i=1;i<=n;i++){
        if (findx(i) != 1){
            return 0;
        }
    }
    return 1;
}
int main(){
    int x,y,t;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> x >> y >> t;
        a.push_back({x,y,t});
    }
    sort(a.begin(),a.end());
    int lo, hi;
    lo = 0, hi = m;
    while (lo <= hi){
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }
    int ans;
    if (lo > m) ans = -1;
    else ans = a[lo-1].t;
    cout << ans << '\n';
}