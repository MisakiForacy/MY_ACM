#include <iostream>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int b=0,g=0;
    string str;
    getline(cin,str);
    for(int i=0;i<str.length()-2;i++){
        if(str[i]=='b'||str[i+1]=='o'||str[i+2]=='y'){
            b++;
        }
    }
    if(str.length()>3){
        for(int i=0;i<str.length()-3;i++){
            if(str[i]=='g'||str[i+1]=='i'||str[i+2]=='r'||str[i+3]=='l'){
                g++;
            }
        }
    }
    cout << b << endl << g;
}