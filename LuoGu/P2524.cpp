#include <bits/stdc++.h>
using namespace std;
int f[10];
int idx(int n);
int d(int n);
int main(){
    int n,cnt = 0;
    string num;
    cin >> n >> num;
    for(int i=1;i<=n;i++)f[i] = 1;
    for(int i=0;i<n-1;i++){
        cnt += idx(num[i]-'0')*d(n-i-1);
        f[num[i]-'0'] = 0;
    }
    cout << cnt+1 << endl;
}
int idx(int n){
    int cnt = 0;
    for(int i=1;i<n;i++){
        cnt+=f[i];
    }
    return cnt;
}
int d(int n){
    int cnt = 1;
    for(int i=1;i<=n;i++){
        cnt *= i;
    }
    return cnt;
}