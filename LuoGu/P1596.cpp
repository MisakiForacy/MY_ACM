#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int max = -INF,i,j;
    string s1,s2,s3,s4;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    getline(cin,s4);
    vector<int>count(26,0);
    for(i=0;i<s1.length();i++)if('A'<=s1[i]&&s1[i]<='Z')count[s1[i]-'A']++;
    for(i=0;i<s2.length();i++)if('A'<=s2[i]&&s2[i]<='Z')count[s2[i]-'A']++;
    for(i=0;i<s3.length();i++)if('A'<=s3[i]&&s3[i]<='Z')count[s3[i]-'A']++;
    for(i=0;i<s4.length();i++)if('A'<=s4[i]&&s4[i]<='Z')count[s4[i]-'A']++;
    for(vector<int>::iterator it=count.begin();it!=count.end();it++)if(*it>max)max=*it;
    vector<vector<char>>table(max,vector<char>(26,' '));
    for(i=0;i<26;i++)for(j=0;j<count[i];j++)table[max-j-1][i] = '*';
    for(i=0;i<max;i++){
        for(j=0;j<26;j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}