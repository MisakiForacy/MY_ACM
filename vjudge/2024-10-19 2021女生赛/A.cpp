#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int ok = 2;
    vector<int> b(m+1);
    for (int i=1;i<=m;i++){
        cin >> b[i];
    }
    if (y > x){
        for (int i=1;i<=m;i++){
            if (x + i > n){
                ok = 0;
                break;
            }
            if (b[i] != a[x + i]){
                ok = 0;
                break;
            }
        }
        if (ok){
            for (int i=1;i<=m;i++){
                if (x - i < 1){
                    ok = 1;
                    break;
                }
                if (b[i] != a[x - i]){
                    ok = 1;
                    break;
                }
            }
        }
    } else{
        for (int i=1;i<=m;i++){
            if (x - i < 1){
                ok = 0;
                break;
            }
            if (b[i] != a[x - i]){
                ok = 0;
                break;
            }
        }
        if (ok){
            for (int i=1;i<=m;i++){
                if (x + i > n){
                    ok = 1;
                    break;
                }
                if (b[i] != a[x + i]){
                    ok = 1;
                    break;
                }
            }
        }
    }
    if (ok == 0){
        cout << "Wrong\n";
    } else if (ok == 1){
        cout << "Right\n";
    } else{
        cout << "Unsure\n";
    }
}