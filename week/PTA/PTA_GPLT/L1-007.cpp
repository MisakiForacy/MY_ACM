#include <iostream>
using namespace std;
const string a[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    int i;
    string n;
    cin >> n;
    for(i=0;i<n.size()-1;i++){
        if(n[i]!='-')cout << a[n[i]-'0'] << " ";
        else cout << "fu ";
    }
    cout << a[n[i]-'0'];
    return 0;
}