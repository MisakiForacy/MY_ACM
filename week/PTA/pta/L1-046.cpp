#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    int len=1,g=1;
    cin >> x;
    while(g<x){
        g = g*10 + 1;
        len++;
    }
    while(true){
        cout << g/x;
        g = g%x;
        if(g==0)break;
        g = g*10+1;
        len++;
    }
    cout << " " << len << endl;
}