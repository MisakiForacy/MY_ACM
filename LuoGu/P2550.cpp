#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,count;
    cin >> n;
    vector<int>a(7);
    vector<int>b(7);
    vector<int>c(7,0);
    for(int i=0;i<7;i++){
        cin >> a[i];
    }
    for(int t=0;t<n;t++){
        count = 0;
        for(int i=0;i<7;i++){
            cin >> b[i];
            for(int j=0;j<7;j++){
                if(a[j] == b[i])count++;
            }
        }
        if(count!=0)c[7-count]++;
    }
    for(vector<int>::iterator it=c.begin();it!=c.end();it++){
        cout << *it << " ";
    }
    return 0;
}