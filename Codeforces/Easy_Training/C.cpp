#include <bits/stdc++.h>
using namespace std;
int t;
bool flg;
string line,s;
int main(){
    cin >> t;
    while(t --){
        flg = false;
        s.clear();
        vector<vector<char>>m(8,vector<char>(8));
        for(int i=0;i<8;i++){
            cin >> line;
            for(int j=0;j<8;j++){
                m[i][j] = line[j];
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(m[i][j]!='.'){
                    for(int k=i;k<8;k++){
                        if(m[k][j]!='.'){
                            s.push_back(m[k][j]);
                        }
                        else break;
                    }
                    flg = true;
                    break;
                }
            }
            if(flg)break;
        }
        cout << s << endl;
    }
}