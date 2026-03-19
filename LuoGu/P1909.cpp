#include <iostream>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
int main(){
    ll n,min=INF,number,price,total;
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> number >> price;
        if(n%number)total = price*(n/number+1);
        else total = price * (n/number);
        if(total<min){
            min = total;
        }
    }
    cout << min;
    return 0;
}