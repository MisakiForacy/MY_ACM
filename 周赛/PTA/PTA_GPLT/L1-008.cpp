#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int i,x,y,line=0,sum=0;
    cin >> x >> y;
    vector<int>a;
    for(i=x;i<=y;i++){
        a.push_back(i);
    }
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        if(line++==5)cout << endl,line=1;
        printf("%5d",*it);
        sum+=*it;
    }
    cout << endl << "Sum = " << sum;
}