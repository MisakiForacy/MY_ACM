#include <iostream>
int main(){
    int k,kk=0;
    std::cin >> k;
    while(k-kk>=0)k-=++kk;
    std::cout << kk*(kk+1)*(2*kk+1)/6+k*(kk+1);
}