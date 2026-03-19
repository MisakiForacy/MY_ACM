#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int i,j;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(i=0;i<s1.length();i++){
        for(j=0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                string ss1(s1,0,i);
                string ss2(s1,i+1);
                s1 = ss1+ss2;
            }
        }
    }
    cout << s1;
}