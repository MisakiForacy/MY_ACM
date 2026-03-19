#include <iostream>
using namespace std;
#define A (!(x&1))
#define B ((4<x)&(x<=12))
int a,b,c,d;
int main(){
    int x;
    cin >> x;  
    if(A&B)a=1;
    if(A|B)b=1;
    if(A^B)c=1;
    if((!A)&(!B))d=1;
    cout << a << " " << b << " "  << c << " "  << d;
}