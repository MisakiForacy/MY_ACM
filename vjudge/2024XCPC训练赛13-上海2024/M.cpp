#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int x = ceil(sqrt(double(n)));
    int a = (x-1) * (n/x) + max(0,n%x-1);
    int b = max(n/x-1,0)*x + n%x;
    int m = min(a,b);
    cout << m << '\n';
    if (n > 2){
        int cnt = 0;
        for (int i=1;i<(x-1)*x;i+=x){
            for (int j=i+1;j<i+x;j++){
                cout << j-1 << ' ' << j << '\n';
                cnt ++;
                if (cnt == m) goto next;
            }
        }
        for (int j=(x-1)*x+2;j<=n;j++){
            cout << j-1 << ' ' << j << '\n';
            cnt ++;
            if (cnt == m) goto next;
        }
        next: cnt = 0;
        for (int i=x+1;i<(x-1)*x;i+=x){
            for (int j=i;j<i+x;j++){
                cout << j-x << ' ' << j << '\n';
                cnt ++;
                if (cnt == m) goto end;
            }
        }
        for (int j=(x-1)*x+1;j<=n;j++){
            cout << j-x << ' ' << j << '\n';
            cnt ++;
            if (cnt == m) goto end;
        }
        end:;
    }
}