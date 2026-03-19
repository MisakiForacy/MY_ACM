#include <iostream>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
using namespace std;
int count(int n){
    int sum=0;
    while(n!=0){
        if(n%10==2)sum+=1;
        n = n/10;
    }
    return sum;
}
int main(){
    int L,R,sum=0;
    cin >> L >> R;
    FOR(i,L,R+1,1){
        sum += count(i);
    }
    cout << sum;
    return 0;
}