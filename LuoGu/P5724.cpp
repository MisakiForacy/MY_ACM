#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,Max = -INF,Min = INF;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<Min)Min=a[i];
        if(a[i]>Max)Max=a[i];
    }
    cout<<Max-Min;
    return 0;
}