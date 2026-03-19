#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n,ai,min=INF;
    cin >> n;
    vector<int>a;
    while(n--){
        cin>>ai;
        a.push_back(ai);
    }
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        if((*it<min)&(*it>=0))min=*it;
    }
    cout << min;
    return 0;
}