#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int cc = 0;
    vector<int>l(3);
    for(int i=0;i<3;i++){
        cin >> l[i];
        if(l[i] > l[cc]) cc = i; 
    }
    int aa,bb,a,b,c;
    aa = (cc+1)%3;bb = (cc+2)%3;
    a = l[aa];b = l[bb];c = l[cc];
    if(a+b<=c || a==0 || b==0 || c==0){cout<<"Not triangle";return 0;}
    else if (a*a+b*b==c*c)cout << "Right triangle" << endl;
    else if (a*a+b*b>c*c) cout << "Acute triangle" << endl;
    else if (a*a+b*b<c*c) cout << "Obtuse triangle" << endl;
    if (a==b || b==c || a==c && a!=0 && b!=0 && c!=0) cout << "Isosceles triangle" << endl;
    if (a==b && b==c && a==c && a!=0 && b!=0 && c!=0) cout << "Equilateral triangle" << endl;
    return 0;
}