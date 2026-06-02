#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string str;
    getline(cin,str);
    str.insert(str.find("int main()")+10,"\n");
    int i;
    for(i=0;i<str.length();i++){
        // if(str[i]==';'){
        //     str.insert(i+1,"\n");
        // }
        if(str[i]=='{'){
            str.insert(i+1,"\n");
        }
        else if(str[i]=='}'){
            // str.insert(i-1,"\n");
            str.insert(i+1,"\n");
            i+=1;
        }
    }
    while(str.find("if")!=-1){
        for(int i=str.find("if");i<str.length();i++){
            if(str[i]==')'){
                str.insert(i+1,"{\n");
                break;        
            }
        }
        str[str.find("if")] = 'I';
    }
    cout << str;
}