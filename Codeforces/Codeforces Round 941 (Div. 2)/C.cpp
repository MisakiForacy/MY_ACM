#pragma GCC optimize(o2)
#include <bits/stdc++.h>
#define endl '\n'
#define N 200002
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t,n,l;
    bool flag;
    cin >> t;
    int a[N];
    while(t--){
        flag =true;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        l = unique(a,a+n) - a;
        for(int i=0;i<l;i++){
            if(a[i]!=i+1){
                if(i%2)cout << "Bob" << endl;
                else cout << "Alice" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            if(!(l%2))cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }
    return 0;
}