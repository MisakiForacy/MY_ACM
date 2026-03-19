#include <bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
using LL = long long;   
const int N = 5e5+10;
int n,m,s[N];
void change(int x,int k){
    while (x <= n){
        s[x] += k;
        x += lowbit(x);
    }
}
int query(int x){
    int t = 0;
    while (x){
        t += s[x];
        x -= lowbit(x);
    }
    return t;
}
int main(){
    cin >> n >> m;
    int op,x,y;
    for (int i=1;i<=n;i++){
        cin >> x;
        change(i,x);
    }
    for (int i=1;i<=8;i++){
        cout << s[i] << " \n"[i==8];
    }
    for (int i=0;i<m;i++){
        cin >> op >> x >> y;
        if (op == 1){
            change(x,y);
        } else{
            cout << query(y) - query(x-1) << '\n';
        }
    }
}