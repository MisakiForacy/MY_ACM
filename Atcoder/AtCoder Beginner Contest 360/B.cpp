#include <bits/stdc++.h>
using namespace std;
bool check(int w,int c,string s,string t){
    for (int i=0;i<t.length();i++){
        char a = s[i*w+c];
        char b = t[i+1];
        if (!isalpha(a)) a = ' ';
        if (!isalpha(b)) b = ' ';
        if (a!=b){    
            return false;
        }
    }
    return true;
}
int main(){
    string s,t;
    int w,c;
    cin >> s >> t;
    s = ' '+s;
    t = ' '+t;
    for (w=1;w<s.length()-1;w++){
        for (c=1;c<=w;c++){
            if (check(w,c,s,t)){
                cout << "Yes\n";
                return 0;
            } else{
                continue;
            }
        }
    }
    cout << "No\n";
    return 0;
}