#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,x;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])b[i]++;
        }
    }
    for(vector<int>::iterator it=b.begin();it!=b.end();it++){
        cout << *it << " ";
    }
    return 0;
}