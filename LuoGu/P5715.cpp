#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int>a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        cout << *it << " ";
    }
    return 0;
}