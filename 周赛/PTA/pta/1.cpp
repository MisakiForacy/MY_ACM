#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    double a,aa;
    cin >> a;
    aa = a;
    double tax;
    vector<int> seg(7);
    seg[1] = 36000 * 0.03;
    seg[2] = seg[1] + (144000-36000) * 0.1 - 2520;
    seg[3] = seg[2] + (300000-144000) * 0.2 - 16920;
    seg[4] = seg[3] + (420000-300000) * 0.25 - 31920;
    seg[5] = seg[4] + (660000-420000) * 0.3 - 52920;
    seg[6] = seg[5] + (960000-660000) * 0.35 - 85920;
    a = max(0.0,a-12*5000);
    if (a > 960000){
        tax = max(0.0,(a-960000)*0.45-181920) + seg[6];
    } else if (a > 660000){
        tax = max(0.0,(a-660000)*0.35-85920) + seg[5];
    } else if (a > 420000){
        tax = max(0.0,(a-420000)*0.3-52920) + seg[4];
    } else if (a > 300000){
        tax = max(0.0,(a-300000)*0.25-31920) + seg[3];
    } else if (a > 144000){
        tax = max(0.0,(a-144000)*0.2-16920) + seg[2];
    } else if (a > 36000){
        tax = max(0.0,(a-36000)*0.1-2520) + seg[1];
    } else{
        tax = a * 0.03;
    }
    printf("salary=%.2f,tax=%.2f",aa,tax);
}