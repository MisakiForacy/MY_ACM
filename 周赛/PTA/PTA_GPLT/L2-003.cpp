#include <algorithm>
#include <iostream>
#include <iomanip>
#define N 10000
using namespace std;
struct type{
    double inventory;
    double price;
    double value;
};
bool cmp(const type&a,const type&b){
    return a.value>b.value;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    int i;
    struct type type[N];  //inventory,price,value
    double res = 0;
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> type[i].inventory;
    for(i=0;i<n;i++)cin >> type[i].price;
    for(i=0;i<n;i++){
        type[i].value = type[i].price / type[i].inventory;
    }
    sort(type,type+n,cmp);
    for(i=0;i<n;i++){
        if(m-type[i].inventory>=0){
            m -= type[i].inventory;
            res += type[i].price;
        }
        else{
            res += m * type[i].value;
            break;
        }
    }
    cout << fixed << setprecision(2) << res << endl;
    return 0;
}