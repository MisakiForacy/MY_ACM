#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    char c;
    int count = 0;
    string str;
    getline(cin,str);
    for(string::iterator it=str.begin();it!=str.end();it++){
        if(*it!=' ')count++;
    }
    cout << count;
}