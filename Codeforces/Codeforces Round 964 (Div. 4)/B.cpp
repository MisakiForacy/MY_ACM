#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int a1,a2,b1,b2;
        int cnt = 0;
        cin >> a1 >> a2 >> b1 >> b2;
        vector<int>a(4);
        a[0] = (a1-b1>0?1:(a1-b1==0?0:-1))+((a2-b2>0?1:(a2-b2==0?0:-1)));
        a[1] = (a1-b2>0?1:(a1-b2==0?0:-1))+((a2-b1>0?1:(a2-b1==0?0:-1)));
        a[2] = (a1-b1>0?1:(a1-b1==0?0:-1))+((a2-b2>0?1:(a2-b2==0?0:-1)));
        a[3] = (a1-b2>0?1:(a1-b2==0?0:-1))+((a2-b1>0?1:(a2-b1==0?0:-1)));
        for (int i=0;i<4;i++){
            if (a[i]>0){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}