#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

static inline bool is_sign(const char s){
    if('A'<=s&&s<='Z')
        return false;
    else if('a'<=s&&s<='z')
        return false;
    else if('0'<=s&&s<='9')
        return false;
    return true;
}

static inline string replace(string str1,const string str2,const int len1,const int len2,const int p){
    int i;
    string s1,s2,str = "";
    for(i=0;i<p;i++){
        s1.push_back(str1[i]);
    }
    for(i=p+len2;i<len1;i++){
        s2.push_back(str1[i]);
    }
    str.append(s1);
    str.append(str2);
    str.append(s2);
    return str;
}

static inline string change(string str){
    int i,str_len;
    str_len = str.length();
    for(i=0;i<str_len;i++){
        if(str[i]=='?')str[i] = '!';
        else if(str[i]=='I'){
            if(i==0 && !is_sign(str[i+1])){
                continue;
            }
            else if(i==str_len-1 && !is_sign(str[i-1])){
                continue;
            }
            else if(!(is_sign(str[i-1]) && is_sign(str[i+1]))){
                continue;
            }
            else{
                str[i] = 'A';
            }
        }
        else if('A'<=str[i] && str[i]<='Z'){
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

static inline string remove_space(string str){
    int i,pre_space_len,fol_space_len,str_len;
    pre_space_len = 0;
    fol_space_len = 0;
    str_len = str.length();
    for(i=str_len-1;i>-1;i--){
        if((is_sign(str[i])) && str[i-1]==' '){
            str.erase(i-1,1);
        }
    }
    str_len = str.length();
    for(i=0;i<str_len;i++){
        if(str[i]!=' ')break;
        pre_space_len++;
    }
    str_len = str.length();
    for(i=str_len-1;i>-1;i--){
        if(str[i]!=' ')break;
        fol_space_len++;
    }
    str.erase(0,pre_space_len);
    str.erase(str.length()-fol_space_len,str.length());
    return str;
}

static inline string find_and_change(string str){
    int index,replace_len,str_len,i;
    str_len = str.length();
    while(str.find("can you")!=-1){     //替换 can you 为 I can
        replace_len = 7;
        index = str.find("can you");
        str_len = str.length();
        if(index==0 && is_sign(str[index+7])){
            str = replace(str,"I can",str_len,replace_len,index);
        }
        else if(is_sign(str[index-1]) && is_sign(str[index+7])){
            str = replace(str,"I can",str_len,replace_len,index);
        }
        else{
            str[index] = toupper(str[index]);
        }
    }
    while(str.find("could you")!=-1){   //替换 could you 为 I could
        replace_len = 9;
        index = str.find("could you");
        str_len = str.length();
        if(index==0 && is_sign(str[index+9])){
            str = replace(str,"I could",str_len,replace_len,index);
        }
        else if(is_sign(str[index-1]) && is_sign(str[index+9])){
            str = replace(str,"I could",str_len,replace_len,index);
        }
        else{
            str[index] = toupper(str[index]);
        }
    }
    while(str.find("me")!=-1){          //替换 me 为 you
        replace_len = 2;
        index = str.find("me");
        str_len = str.length();
        if(index==0 && is_sign(str[index+2])){
            str = replace(str,"you",str_len,replace_len,index);
        }
        else if(is_sign(str[index-1]) && is_sign(str[index+2])){
            str = replace(str,"you",str_len,replace_len,index);
        }
        else{
            str[index] = toupper(str[index]);
        }
    }
    str_len = str.length();
    for(i=0;i<str_len;i++){
        if('B'<=str[i] && str[i]<='Z' && str[i]!='I'){
            str[i] = tolower(str[i]);
        }
        if(str[i]=='A'){
            str = replace(str,"you",str_len,1,i);
        }
    }
    return str;
}

int main(){
    int n;
    int i,j;
    string str;
    cin >> n;
    getchar();
    for(i=0;i<n;i++){
        getline(cin,str);
        cout << str << endl;
        str = change(str);
        str = remove_space(str);
        str = find_and_change(str);
        cout << "AI: " << str << endl; 
    }
}