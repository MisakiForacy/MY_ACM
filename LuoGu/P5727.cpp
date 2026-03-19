#include <iostream>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
#define N 100000
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,len=1;
    cin >> n;
    vector<int>a;
    a.push_back(n);
    while(n!=1){
        if(n&1)n=n*3+1;
        else n=n/2;
        a.push_back(n);
        len++;
    }
    for(vector<int>::reverse_iterator it=a.rbegin();it!=a.rend();it++){
        cout << *it << " ";
    }
    return 0;
}