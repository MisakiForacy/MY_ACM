#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
const int N = 3e5+10;
int n,a[N],b[N];
bool check(int x){
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (a[i] > x){
            cnt ++;
        }
    }
}
int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    LL lo = 0, hi = 1e9;
    while (lo <= hi){
        LL mid = lo + hi >> 1;
        if (check(mid)){
            lo = mid - 1;
        } else{
            hi = mid + 1;
        }
    }
    cout << lo << '\n';
}