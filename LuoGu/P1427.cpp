#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int x,len=0;
    vector<int>a;
    while(true){
        cin >> x;
        if(x==0)break;
        a.push_back(x);
        len++;
    }
    for(int i=len-1;i!=-1;i--){
        cout << a[i] << " ";
    }
    return 0;
}