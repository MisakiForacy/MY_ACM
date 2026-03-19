#include <iostream>
using namespace std;
int main(){
    int x,n,total=0;
    cin>>x>>n;
    for(int i=0;i<n;i++){
        if((x+i)%7!=6 && (x+i)%7!=0)total+=250;
    }
    cout<<total;
    return 0;
}