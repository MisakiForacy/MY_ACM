#include <bits/stdc++.h>
#define N 110
using namespace std;
static int f[N][N];
int main(){
    int n,i,j;
    cin >> n;
    memset(f,0,sizeof(f));
    j = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            if(j==1)f[i][j] = f[i-1][n-i+2];
            f[i][j] += f[i][j-1] + j + (j-i>=1?j-i:0);
        }
    }
    cout << f[i-1][j-1] << endl;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            printf("%5d",f[i][j]);
        }
        cout << endl;
    }
}

// #include<iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// int c[105];
// int d[105];
// using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     int n;
//     cin>>n;
//     int s=n*n;
//     for(int i=1;i<n;i++){
//     	c[i]=(i+1)*i/2;
//         s=s+c[i];
//     }
//     if(n<3) d[n]=0;
//     else{
//     	for(int j=n-3;j>0;j=j-2){
//     		d[n]+=c[j];
//     		//cout<<d[n]<<endl;
// 		}
// 	}
// 	s+=d[n];
//     cout<<s;
//     return 0;
// }