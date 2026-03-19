#include <iostream>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n;
    int count=0;
    string str;
    cin >> n; 
    cin >> str;
    vector<int>ii;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]=='V'&&str[i+1]=='K'){
            ii.push_back(i);
            count++;
        }
    }
    for(vector<int>::reverse_iterator it=ii.rbegin();it!=ii.rend();it++){
        str.insert(*it,"X");
        str.erase(*it+1,2);
    }
    if(str.find("VV")!=-1||str.find("KK")!=-1)count++;
    cout << count;
    return 0;
}