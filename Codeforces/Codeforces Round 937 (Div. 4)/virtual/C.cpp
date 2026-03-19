#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 t, mm, hh, h;
int main(){
    cin >> t;
    while(t --){
        scanf("%d:%d", &hh, &mm);
        h = hh;
        hh = (h > 12 ? h - 12 : h);
        hh = (hh == 0?12:hh);
        cout<<(hh < 10 ? "0":"")<<hh<<":"<<(mm < 10 ? "0":"")<<mm<<(h >= 12?" PM\n":" AM\n");
    }
}