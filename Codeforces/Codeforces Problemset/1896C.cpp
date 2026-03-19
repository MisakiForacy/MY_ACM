#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
const int N = 2e5+10;
int b[N];
struct node{
    LL x,idx;
    bool operator < (const node &that) const {
        return x > that.x;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int ok = 1;
        LL n,x,num;
        cin >> n >> x;
        vector<node> A,B;
        for (int i=0;i<n;i++) cin >> num, A.push_back({num,i});
        for (int i=0;i<n;i++) cin >> num, B.push_back({num,i});
        sort(all(A)), sort(all(B));
        for (int i=0;i<x;i++){
            if (A[i].x > B[n-x+i].x){
                b[A[i].idx] = B[n-x+i].x;
            } else{
                ok = 0;
                break;
            }
        }
        for (int i=x;i<n;i++){
            if (A[i].x <= B[i-x].x){
                b[A[i].idx] = B[i-x].x;
            } else{
                ok = 0;
                break;
            }
        }
        if (ok){
            cout << "YES\n";
            for (int i=0;i<n;i++){
                cout << b[i] << " \n"[i==n-1];
            }
        } else{
            cout << "NO\n";
        }
    }
}