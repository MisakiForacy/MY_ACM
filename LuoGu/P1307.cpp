#include <iostream>
#include <vector>
using namespace std;
int main(){
    char x;
    bool flag1 = false,flag2 = true;
    string num;
    cin >> num;
    if(num=="0"){cout << 0;return 0;}
    if(num[0]=='-')flag1=true;
    if(flag1)cout << '-';
    for(int i=num.size()-1;i>(-1);i--){
        if(num[i]=='-'||(num[i]=='0'&&flag2))continue;
        else cout << num[i],flag2 = false;
    }
    return 0;
}