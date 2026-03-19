#include <bits/stdc++.h>
#define N 1001
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n,lll=0;
    int i,j,k,maxn = -INF,left,line=0,num;
    int a[N];
    int aa[N];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
        aa[i] = a[i];
        if(a[i]>maxn)maxn=a[i];
    }
    int b[N][maxn][10];
    while(maxn--){
        for(i=0;i<n;i++){
            left = 0;
            for(j=0;j<n;j++){
                left+=!(!a[j]);
            }
            if(left==1)left=2;
            if(a[i]!=0){
                for(j=0;j<10;j++){
                    num = left*j+line*10+i+1;
                    b[i][lll][j] = num;
                }
            }
        }
        for(k=0;k<n;k++){
            if(a[k]!=0)a[k]--;
        }
        lll++;
        line+=left;
    }
    for(i=0;i<n;i++){
        cout << "#" << i+1 << endl;
        for(j=0;j<aa[i];j++){
            for(k=0;k<10-1;k++){
                cout << b[i][j][k] << " ";
            }
            cout << b[i][j][k] << endl;
        }
    }
}