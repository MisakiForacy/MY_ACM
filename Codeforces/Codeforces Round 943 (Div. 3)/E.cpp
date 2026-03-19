#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,n,i;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==2){
            cout << "1 1\n2 1\n";
        }
        else{
            cout << "1 1\n2 1\n";
            for(i=3;i<=n;i++){
                cout << i << " " << i << endl;
            }
        }
    }
    return 0;
}