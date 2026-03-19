/*AC代码*/
#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;
struct a{
    int b,num;
};
bool cmp(a x,a y){
    return x.b<y.b;
}
int main(){
    struct a a[N];
    int n,i,j;
    double time = 0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i].b;
        a[i].num = i;
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++){
        cout << a[i].num << " ";
    }cout << endl;
    for(j=n-1;j>=1;j--){
        i = n - j;
        time += a[i].b*j;
    }
    printf("%.2lf",time/n);
    return 0;
}