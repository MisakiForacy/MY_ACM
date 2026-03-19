#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    bool flag = true;
    int a,b;
    double c;
    string s1,s2,s3;
    cin >> a >> b;
    s1 = to_string(a);
    if(b<0)s2 = "(" + to_string(b) + ")";else s2 = to_string(b);
    if(b==0){
        cout << s1 << "/" << s2 << "=Error";
    }
    else{
        c = (double)a/b;
        cout << fixed << setprecision(2) << s1 << "/" << s2 << "=" << c;
    }
    return 0;
}