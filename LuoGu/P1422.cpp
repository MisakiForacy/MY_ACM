#include <iostream>
#include <iomanip>
#define elif else if
using namespace std;
typedef double db;
typedef long long ll;
int main(){
    db total,price;
    cin >> total;
    if(total<=150)price = total * 0.4463;
    elif(total<=400)price = 150 * 0.4463 + (total-150) * 0.4663;
    else price = 150 * 0.4463 + 250 * 0.4663 + (total-400) * 0.5663;
    cout<<fixed<<setprecision(1)<<price;
    return 0; 
}