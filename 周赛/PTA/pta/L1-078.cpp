#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    int m,n;
    cin >> n >> m;
    vector<string>a(n);
    vector<string>b;
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,a[i]);
        if(int(a[i].find("easy"))==-1&&int(a[i].find("qiandao"))==-1){
            b.push_back(a[i]);
        }
    }
    if(m>=b.size())cout<<"Wo AK le"<<endl;
    else cout<<b[m]<<endl;
}