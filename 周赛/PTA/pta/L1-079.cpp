#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,i;
    int maxn = -INF,minn = INF;
    int maxc = 0   ,minc = 0;
    cin >> n;
    vector<int>a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxn)maxn=a[i];
        if(a[i]<minn)minn=a[i];
    }
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        if(*it==maxn)maxc++;
        if(*it==minn)minc++;
    }
    cout << minn << " " << minc << endl;
    cout << maxn << " " << maxc << endl;
    return 0;
}