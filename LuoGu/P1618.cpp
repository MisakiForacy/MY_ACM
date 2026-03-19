#include <bits/stdc++.h>
using namespace std;
int a,b,c;
bool check(int n1,int n2,int n3){
    int n[10]={0};
    for (int i=0;i<3;i++){
        n[int(n1/pow(10,i))%10]++;
        n[int(n2/pow(10,i))%10]++;
        n[int(n3/pow(10,i))%10]++;
    }
    for (int i=1;i<=9;i++){
        if (n[i]!=1) return 0;
    }
    return 1;
}
int main(){
    int flg = 1;
    cin >> a >> b >> c;
    for (int n1=100;n1<=333;n1++){
        int n2 = n1 * (1.0*b/a);
        int n3 = n2 * (1.0*c/b);
        if (check(n1,n2,n3)){
            cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
            flg = 0;
        }  
    }
    if (flg) cout << "No!!!\n";
}