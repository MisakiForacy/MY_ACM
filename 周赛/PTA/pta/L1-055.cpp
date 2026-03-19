#include <iostream>
using namespace std;
int main(){
    int pa1,pa2=0,pb1,pb2=0;
    int p1,p2;
    int a,b,c;
    char x;
    cin >> pa1 >> pb1;
    cin >> a >> b >> c;
    if(a)pb2++;else pa2++;
    if(b)pb2++;else pa2++;
    if(c)pb2++;else pa2++;
    if(pa1>pb1&&pa2!=0){
        p1 = pa1;
        p2 = pa2;
        x = 'a';
    }
    else if(pa1>pb1&&pa2==0){
        p1 = pb1;
        p2 = pb2;
        x = 'b';
    }
    else if(pa1<pb1&&pb2!=0){
        p1 = pb1;
        p2 = pb2;
        x = 'b';
    }
    else{
        p1 = pa1;
        p2 = pa2;
        x = 'a';
    }
    cout << "The winner is " << x << ": " << p1 <<" + " << p2 << endl;
}