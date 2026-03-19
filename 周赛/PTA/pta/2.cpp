#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int x;
    cin >> x;
    int ok = 1;
    for (int i=0;i<=9999;i++){
        int a = i / 1000 % 10;
        int b = i / 100 % 10;
        int c = i / 10 % 10;
        int d = i % 10;
        if (a!=0 && d!=0 && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            int e = i * x;
            int dd = e / 1000 % 10;
            int cc = e / 100 % 10;
            int bb = e / 10 % 10;
            int aa = e % 10;
            if (e<10000 && a==aa && b==bb && c==cc && d==dd){
                printf("%d * %d = %d\n",i,x,e);
                ok = 0;
                // return 0;
            }
        }
    }
    if (ok) printf("None\n");
}