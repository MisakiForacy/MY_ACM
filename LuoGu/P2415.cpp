#include <bits/stdc++.h>
#define N 10000
using namespace std;
int main(){
    long long x,s=0;
    int i,a[N];
    while(cin >> a[i++])if(getchar()=='\n')break;
    for(int j=0;j<i;j++){
        x = (int)pow(2,i-1);
        s+=x*a[j];
    }
    cout << s;
}