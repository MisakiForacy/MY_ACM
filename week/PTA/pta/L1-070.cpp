#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    bool flag = true;
    int count=0,len=0,first;
    while(1){
        getline(cin,str);
        if(str!="."){
            len++;
            if(str.find("chi1 huo3 guo1")>=0&&str.find("chi1 huo3 guo1")<str.length()){
                if(flag){
                    flag = false;
                    first = len;
                }
                count++;
            }
        }
        else break;
    }
    cout << len << endl;
    if(count)cout << first << " " << count << endl;
    else cout << "-_-#" << endl;
    return 0;
}