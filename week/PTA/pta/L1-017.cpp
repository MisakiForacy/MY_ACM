#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    string s;
    cin >> s;
    int i,digit;
    db total,count=0;
    for(i=0;i<s.length();i++){
        if(s[i]=='2')count++;
    }
    digit = (s[0]=='-'?s.length()-1:s.length());
    total=count/digit;
    cout << fixed << setprecision(2) << total * (s[0]=='-'?1.5:1) * ((s[-1]-'0')%2?1:2) * 100 << "%" << endl;
}