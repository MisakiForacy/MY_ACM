#include <bits/stdc++.h>
using namespace std;
int main(){
    int l1,l2,l3,l4,Min,datle;
    int Max;
    bool p1=0,p2=0,p3=0,p4=0;
    cin >> l1 >> l2 >> l3 >> l4 >> Min >> datle;
    Max = max(l1,max(l2,max(l3,l4)));
    if(Max-l1>datle || l1<Min)p1=1;
    if(Max-l2>datle || l2<Min)p2=1;
    if(Max-l3>datle || l3<Min)p3=1;
    if(Max-l4>datle || l4<Min)p4=1;
    if(p1+p2+p3+p4==0)cout<<"Normal"<<endl;
    else if(p1+p2+p3+p4>1)cout<<"Warning: please check all the tires!"<<endl;
    else{
        if(p1)cout<<"Warning: please check #1!"<<endl;
        else if(p2)cout<<"Warning: please check #2!"<<endl;
        else if(p3)cout<<"Warning: please check #3!"<<endl;
        else if(p4)cout<<"Warning: please check #4!"<<endl;
    }
    return 0;
}