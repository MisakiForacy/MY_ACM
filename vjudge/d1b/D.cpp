#include <bits/stdc++.h>
using namespace std;
bool check(int n1,int n2){
    int rec[100] = {0};
    for (int i=0;i<5;i++){
        rec[int(n1/pow(10,i))%10]++;
        rec[int(n2/pow(10,i))%10]++;
    }
    for (int i=0;i<10;i++){
        if (rec[i]!=1) return 0;
    }
    return 1;
}
int main(){
    int n,t=0;
    while (cin >> n){
        if (!n) break;
        if (t) cout << '\n';
        t ++;
        int flg = 1;
        for (int n1=1;n1<=9;n1++)
        for (int n2=0;n2<=9;n2++)
        for (int n3=0;n3<=9;n3++)
        for (int n4=0;n4<=9;n4++)
        for (int n5=0;n5<=9;n5++){
            int num = n1*10000+n2*1000+n3*100+n4*10+n5;
            if (!(num%n)){
                if (check(num,num/n)){
                    printf("%05d / %05d = %d\n",num,num/n,n);
                    flg = 0;
                }
            }
        }
        if (flg){
            printf("There are no solutions for %d.\n",n);
        }
    }
}