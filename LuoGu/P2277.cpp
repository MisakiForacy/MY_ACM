#include <bits/stdc++.h>
using namespace std;
vector<int>a(4);
vector<int>op(3);
char ch[4] = {'+','-','*','/'};
const int inf = 0x3f3f3f3f;
int opt(int a,int b,int opp){
    if (opp==1){
        return a + b;
    } else if (opp==2){
        if (b > a) return inf;
        return a - b;
    } else if (opp==3){
        return a * b;
    } else{
        if (b == 0) return inf;
        if (a % b) return inf;
        return a / b;
    }
}
int check_1(){
    int n = a[0];           // a op b op c op d == 24
    for (int i=1;i<4;i++){
        n = opt(n,a[i],op[i-1]);
        if (n == inf) break;
    }
    if (n==24) return 1;
    return 0;
}

int check_2(){
    int n = opt(a[2],a[3],op[2]); // a op b op (c op d) == 24
    int m = opt(a[0],a[1],op[0]);
    if (n == inf || m == inf) return 0;
    n = opt(m,n,op[1]);
    if (n == inf) return 0;
    if (n == 24) return 2;
    return 0;
}

int main(){
    int cnt = 0;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(),a.end());
    do{
        for (int i=1;i<=4;i++){
            for (int j=1;j<=4;j++){
                for (int k=1;k<=4;k++){
                    op[0] = i, op[1] = j, op[2] = k;
                    if (check_1()){
                        cnt ++;
                    } else if (check_2()){
                        cnt ++;
                    }
                }
            }
        }
    } while (next_permutation(a.begin(),a.end()));
    // a = {6,8,9,7};
    // op = {3,4,2};
    // cout << check() << '\n';
    cout << cnt << '\n';
}