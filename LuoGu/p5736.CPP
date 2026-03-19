#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static inline bool is_prime(int num);
int main(){
    int n,x;
    cin >> n;
    vector<int>a;
    for(int i=0;i<n;i++){
        cin >> x;
        if(is_prime(x)&&x!=1)
            a.push_back(x);
    }
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)cout << *it << " ";
}
static inline bool is_prime(int num){
    for(int i=2;i<=int(sqrt(num));i++)if(!(num%i))return false;
    return true;
}