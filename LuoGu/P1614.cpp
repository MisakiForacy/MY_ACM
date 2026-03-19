#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,m,min=INF,sum;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<=n-m;i++){
        sum = 0;
        for(int j=i;j<i+m;j++){
            sum += a[j];   
        }
        if(sum<min)
            min=sum;
    }
    cout << min;
    return 0;
}