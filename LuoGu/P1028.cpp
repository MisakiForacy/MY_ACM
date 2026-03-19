#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N 1005
using namespace std;
// int s[N];
// int f(int n);
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     memset(s,-1,sizeof(s));
//     int n;
//     cin >> n;
//     cout << f(n);
// }
// int f(int n){
//     int res = 1;
//     if(n==1)return 1;
//     for(int i=1;i<=n/2;i++){
//         if(s[i]!=-1){
//             res += s[i];
//         }
//         else{
//             res += f(i);
//             s[i] = res;
//         }
//         // res += f(i);
//     }
//     return res;
// }
static int f[N];
int main(){
    int n,m;
    cin >> n;
    m = n/2;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        if(i%2)f[i] = f[i-1];
        else f[i] = f[i-1] + f[i/2];
    }
    cout << f[n] << endl;
    return 0;
}