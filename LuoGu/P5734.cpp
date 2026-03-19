#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define elif else if
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,a,b,comm,position=-1;
    string str,ss;
    cin >> n >> str;
    while(n--){
        position = -1;
        cin >> comm;
        if(comm == 1){
            cin >> ss;
            str.append(ss);
            cout << str << endl;
        }
        elif(comm == 2){
            cin >> a >> b;
            str.erase(a+b);
            str.erase(0,a);
            cout << str << endl;
        }
        elif(comm == 3){
            cin >> a >> ss;
            str.insert(a,ss);
            cout << str << endl;
        }
        elif(comm == 4){
            cin >> ss;
            if(str.find(ss)<=str.length())position = str.find(ss);
            cout << position << endl;
        }
    }
    return 0;
}