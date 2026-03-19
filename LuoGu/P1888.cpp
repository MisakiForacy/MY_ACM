#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,Max,Min,Gcd;
    cin >> a >> b >> c;
    Max = max(a,max(b,c));
    Min = min(a,min(b,c));
    Gcd = __gcd(Max,Min);
    cout << Min/Gcd << "/" << Max/Gcd;
    return 0;
}