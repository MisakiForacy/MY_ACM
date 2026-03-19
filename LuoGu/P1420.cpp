#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,count=1,max=1;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]==1)count+=1;
        else{
            if(count>max)max=count;
            count = 1;
        }
    }
    if(count>max)max=count;
    std::cout << max;
}