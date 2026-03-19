#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    ll ss1=1,ss2=1;
    for(int i=0;i<s1.length();i++){
        ss1 *= (s1[i]-'A'+1);
    }
    ss1=ss1%47;
    for(int i=0;i<s2.length();i++){
        ss2 *= (s2[i]-'A'+1);
    }
    ss2=ss2%47;
    cout << (ss1==ss2?"GO":"STAY") << endl;
    return 0;
}