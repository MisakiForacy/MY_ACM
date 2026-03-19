#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    ll cnt = 0;
    for (int i=0;i<n;i++){
        if (cnt%3==0){
            cnt += (a[i]/5)*3;
            if (a[i]%5<=2){
                cnt += a[i]%5;
            } else{
                cnt += 3;
            }
        } else if (cnt%3==1){
            if (a[i]==1){
                cnt += 1;
            } else if (a[i]<=4){
                cnt += 2;
            } else{
                a[i] -= 4;
                cnt += 2;
                cnt += (a[i]/5)*3;
                if (a[i]%5<=2){
                    cnt += a[i]%5;
                } else{
                    cnt += 3;
                }
            }
        } else{
            if (a[i]<=3){
                cnt += 1;
            } else{
                a[i] -= 3;
                cnt += 1;
                cnt += (a[i]/5)*3;
                if (a[i]%5<=2){
                    cnt += a[i]%5;
                } else{
                    cnt += 3;
                }
            }
        }
    }
    cout << cnt << '\n';
}