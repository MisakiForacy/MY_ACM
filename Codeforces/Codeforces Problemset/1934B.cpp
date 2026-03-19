#include <bits/stdc++.h>
using namespace std;
const int b[] = {15,10,6,3,1};
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,cnt = 0;
        cin >> n;
        for (int i=0;i<5;i++){
            cnt += n/b[i];
            n = n%b[i];
        }
        cout << cnt << '\n';
    }
}