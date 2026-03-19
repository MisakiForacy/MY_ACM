#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N 1005
#define endl '\n'
using namespace std;
typedef long long ll;
int a[N];
bool flag;
ll n,m,k,t;
ll d,i,j,s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        flag = false;
        cin >> n;
        for(i=1;i<=n;i++){
            cin >> a[i];
        }
        for(i=1;i<=n;i++){
            if(a[a[i]]==i){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << 2 << endl;
        }
        else cout << 3 << endl;
    }
    return 0;
}