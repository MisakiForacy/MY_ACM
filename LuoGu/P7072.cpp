#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,w;
    cin >> n >> w;
    int s[100010];
    int b[1000];
    for (int i=0;i<=600;i++) b[i] = 0;
    for (int i=1;i<=n;i++){
        cin >> s[i];
        b[s[i]] ++;
        int num = max(1,i*w/100);
        
        for (int i=0;i<=600;i++){

        }
        int sc = s[max(1,i*w/100)];
        cout << sc << " \n"[i==n];
    }
}