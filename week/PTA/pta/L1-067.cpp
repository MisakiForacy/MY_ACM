#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double a,b,c;
    string n;
    cin >> a >> b >> c;
    if(b){
        a = a*1.26;
    }
    else{
        a = a*2.455;
    }
    if(a>c)n = " ^_^";else n=" T_T";
    cout << fixed << setprecision(2) << a << n << endl;
}