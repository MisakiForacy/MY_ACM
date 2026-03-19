#include <bits/stdc++.h>
using namespace std;
const char h[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main(){
    char c;
    int cc;
    string ccc;
    // while(scanf("%c",&c)!=EOF){
    //     getchar();
    c = getchar();
    ccc = "";
    cc = int(c);
    while(cc!=0){
        ccc.push_back(h[cc%16]);
        cc = cc/16;
    }
    reverse(ccc.begin(),ccc.end());
    cout << "#include<stdio.h>" << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    cout << "    printf(\"%c\\n\",\'\\x" << ccc << "\');" << endl;
    cout << "}" << endl;
    // }
}