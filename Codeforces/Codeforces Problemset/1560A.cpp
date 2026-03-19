#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,m[1005];
    t = 1;
    for (int i=1;i<10000;i++){
        if (i%3==0){
            continue;
        } else if(i%10==3){
            continue;
        } else{
            m[t] = i;
            t ++;
        }
        if (t==1001){
            break;
        }
    }
    int T,n;
    cin >> T;
    while (T--){
        cin >> n;
        cout << m[n] << '\n';
    }
}