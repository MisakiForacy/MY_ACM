#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef double db;
const char identification_code[] = {'0','1','2','3','4','5','6','7','8','9','X'};
int main(){
    string ISBN;
    int sum=0,weight=0;
    char id_code;
    cin >> ISBN;
    vector<int>num;
    for(int i=0;i<ISBN.length()-1;i++){
        if(('0'<=ISBN[i])&('9'>=ISBN[i]))num.push_back(ISBN[i]-'0');
    }
    for(vector<int>::iterator it=num.begin();it!=num.end();it++){
        weight++;
        sum += *it * weight;
    }
    id_code = identification_code[sum%11];
    if(id_code==ISBN[12])cout<<"Right";
    else cout<<ISBN.substr(0,12)<<id_code;
    return 0;
}