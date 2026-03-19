#include <iostream>
using namespace std;
int main(){
    int n,x,nn,count=0;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        nn = i;
        while(nn!=0){
            if(nn%10==x)count++;
            nn /= 10;
        }
    }
    cout << count;
}