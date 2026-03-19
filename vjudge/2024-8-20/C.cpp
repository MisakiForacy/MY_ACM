#include <bits/stdc++.h>
using namespace std;
int a[100005];
void init(){
    a[1] = 1;
    for (int i=2;i*i<=100000;i++){
        if (!a[i]){
            for (int j=i*i;j<=100000;j+=i){
                a[j] = 1;
            }
        }
    }
}
int main(){
    init();
    int n;
    while (cin >> n){
        if (n < 0) break;
        int cnt = 0;
        for (int i=2;i<=n-2;i++){
            if (!a[i] && !a[i+2]){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}