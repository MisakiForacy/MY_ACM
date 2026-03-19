#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j;
    char c = 'a';
    string s;
    string s1,s2;
    cin >> s;
    for(i=0;i<s.length();i++){
        if(s[i]<'0'||s[i]>'9'){
            c = s[i];
            break;
        }
    }
    if(c == 'a'){
        for(i=s.length()-1;i>-1;i--){
            s1.push_back(s[i]);
        }
        int len=0;
        for(i=0;i<s1.length()-1;i++){
            if(s1[i]=='0'){
                len++;
            }
            else break;
        }
        s1.erase(0,len);
        cout << s1 << endl;
    }
    else if(c == '.'){
        for(i=s.find('.')-1;i>-1;i--){
            s1.push_back(s[i]);
        }
        int len1=0 , len2=0;
        for(i=0;i<s1.length()-1;i++){
            if(s1[i]=='0'){
                len1++;
            }
            else break;
        }
        s1.erase(0,len1);

        if(s.length()-s.find('.')-1>1){
            for(i=s.find('.')+1;i<s.length();i++){
                if(s[i]=='0'){
                    len2++;
                }
                else break;
            }
        }
        for(i=s.length()-1;i>s.find('.')+len2;i--){
            s2.push_back(s[i]);
        }
        cout << s1 << "." << s2 << endl;
    }
    else if(c == '/'){
        for(i=s.find('/')-1;i>-1;i--){
            s1.push_back(s[i]);
        }
        for(i=s.length()-1;i>s.find('/');i--){
            s2.push_back(s[i]);
        }
        int len1=0 , len2=0;
        for(i=0;i<s1.length()-1;i++){
            if(s1[i]=='0'){
                len1++;
            }
            else break;
        }
        for(i=0;i<s2.length()-1;i++){
            if(s2[i]=='0'){
                len2++;
            }
            else break;
        }
        s1.erase(0,len1);
        s2.erase(0,len2);
        cout << s1 << "/" << s2 << endl;
    }
    else if(c == '%'){
        for(i=s.length()-2;i>-1;i--){
            s1.push_back(s[i]);
        }
        int len=0;
        for(i=0;i<s1.length()-1;i++){
            if(s1[i]=='0'){
                len++;
            }
            else break;
        }
        s1.erase(0,len);
        cout << s1 << "%" << endl;
    }
}