#include <bits/stdc++.h>
using namespace std;
vector<int> a(6);
int sc(int n){
    if (n<3) return a[0];
    else if (n<7) return a[1];
    else if (n<30) return a[2];
    else if (n<120) return a[3];
    else if (n<365) return a[4];
    else return a[5];
}
int main(){
    int n,x;
    int sum,cnt;
    sum = cnt = 0;
    cin >> n;
    for (int i=0;i<6;i++) cin >> a[i];
    while (n--){
        cin >> x;
        if (x){
            cnt ++;
            sum += sc(cnt);
        } else{
            cnt = 0;
        }
    }
    cout << sum << '\n';
}