#include <bits/stdc++.h>
#define debug(x) cout << #x << ":" << x << '\n'
using namespace std;
typedef long long i64;
const i64 inf = 0x3f3f3f3f3f3f3f;
bool cmp(i64 a,i64 b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    i64 T,n,mi,idx;
    cin >> T;
    while (T--){
        mi = inf;
        cin >> n;
        vector<i64>ar(n);
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        sort(ar.begin(),ar.end());
        if (n==2){
            cout << ar[0] << " " << ar[1] << '\n';
            continue;
        }
        for (int i=0;i<n-1;i++){
            if (ar[i+1]-ar[i]<=mi){
                mi = ar[i+1]-ar[i];
                idx = i;
            }
        }
        swap(ar[0],ar[idx]);
        swap(ar[n-1],ar[idx+1]);
        sort(ar.begin()+1,ar.end()-1);
        idx = 0;
        for (int i=1;i<n-1;i++){
            if (ar[i]>=ar[0]){
                idx = i;
                break;
            }
        }
        cout << ar[0];
        if (idx){
            for (int i=idx;i<n-1;i++){
                cout << " " << ar[i];
            }
            for (int i=1;i<idx;i++){
                cout << " " << ar[i];
            }
        } else{
            for (int i=1;i<n-1;i++){
                cout << " " << ar[i];
            }
        }
        cout << " " << ar[n-1] << '\n';
    }
}