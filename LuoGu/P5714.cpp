#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef double db;
int main(){
    db m,h,bmi;
    cin >> m >> h;
    bmi = m/(h*h);
    if(bmi<18.5)cout<<"Underweight";
    else if(bmi<24)cout<<"Normal";
    else cout<<setprecision(6),cout<<bmi<<endl<<"Overweight";
    return 0;
}