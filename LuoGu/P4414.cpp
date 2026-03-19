#include <iostream>
#include <algorithm>
#define elif else if
using namespace std;
int main(){
    int n1,n2,n3,A,B,C;
    string rule;
    cin >> n1 >> n2 >> n3;
    A = min(n1,min(n2,n3));
    C = max(n1,max(n2,n3));
    if((A<n1)&(n1<C))B=n1;
    elif((A<n2)&(n2<C))B=n2;
    elif((A<n3)&(n3<C))B=n3;
    cin >> rule;
    for(int i=0;i<3;i++){
        if(rule[i]=='A')cout << A << " ";
        elif(rule[i]=='B')cout << B << " ";
        elif(rule[i]=='C')cout << C << " ";
    }
    return 0;
}