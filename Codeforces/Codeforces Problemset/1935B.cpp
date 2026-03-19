#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int a[N],b[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>ar(n);
        int lo = 0;
        int mexa = 0, mexb = 0;
        int update;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=0;i<n;i++){
            update = 0;
            cin >> ar[i];
            a[ar[i]] ++;
            while (a[mexa]){
                mexa ++;
                update = 1;
            }
            if (update){
                lo = i;
            }
        }
        for (int i=n-1;i>lo;i--){
            b[ar[i]] ++;
            while (b[mexb]){
                mexb ++;
            }
        }
        if (mexa==mexb){
            cout << 2 << '\n';
            cout << 1 << ' ' << lo + 1 << '\n';
            cout << lo + 2 << ' ' << n << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}