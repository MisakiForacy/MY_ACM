#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);  // PI
int main(){
    int n;
    while (cin >> n){
        double d = sin(PI / n);
        double h = cos(PI / n);
        printf("%.6lf\n", d * h * (n - 1) + d);
    }
}