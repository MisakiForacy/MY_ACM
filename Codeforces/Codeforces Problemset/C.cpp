#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    int a,b;
    bool operator < (const haha &that) const{
        return a < that.a;
    }
};
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<haha>a(n);
        for (int i=0;i<n;i++) cin >> a[i].a;
        for (int i=0;i<n;i++) cin >> a[i].b;
        sort(a.begin(),a.end());
        ll mid = a[n/2];
        ll mx = a[n-1];
        int hi,lo;
        hi = lo = -1;
        for (int i=n-1;i>n/2;i--){
            if (a[i].b){
                hi = i;
                break;
            }
        }
        for (int i=n/2;i>=0;i--){
            if (a[i].b){
                lo = i;
                break;
            }
        }
        if (lo == -1 && hi != -1){
            mx = a[hi].a + k;
            cout << mid + mx << '\n';
        } else if (lo != -1 && hi == -1){
            if (a[lo].a + k > a[n/2+1].a){

            } else{

            }
        } else if (lo == -1 && hi == -1){
            cout << mid + mx << '\n';
        } else{

        }
    }
}