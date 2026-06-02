#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    bool flag1,flag2;
    int i,j,space;
    string str;
    cin >> n;
    getchar();
    while(n--){
        space = 0;
        flag1 = false;flag2 = false;
        getline(cin,str);
        for(i=0;i<str.length();i++){
            if(str[i]==','){
                if(str[i-3]=='o'&&str[i-2]=='n'&&str[i-1]=='g'){
                    flag1 = true;
                }
            }
            if(str[i]=='.'){
                if(str[i-3]=='o'&&str[i-2]=='n'&&str[i-1]=='g'){
                    flag2 = true;
                }
                break;
            }
        }
        if(flag1&&flag2){
            for(i;i>-1;i--){
                if(str[i]==' ')space++;
                if(space==3)break;
            }
            for(j=0;j<=i;j++){
                cout << str[j];
            }
            cout << "qiao ben zhong." << endl;
        }
        else{
            cout << "Skipped" << endl;
        }
    }
    
}