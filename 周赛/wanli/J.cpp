#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,num;
    while(scanf("%d",&n)!=-1){
        num = 9;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout << num;
                num--;
                if(num<0)num=9;
            }
            cout << endl;
        }
    }
}