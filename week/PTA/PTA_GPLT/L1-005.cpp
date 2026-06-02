#include <iostream>
#define N 100000
using namespace std;
struct info{
    string s1;
    int s2;
    int s3;
}a[N],*it;
int main(){
    int n,t,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
    }
    cin >> t;
    while(t--){
        cin >> x;
        for(int i=0;i<n;i++){
            if(x==a[i].s2){
                cout << a[i].s1 << " " << a[i].s3 << endl;
                break;
            }
        }
    }
    return 0;
}