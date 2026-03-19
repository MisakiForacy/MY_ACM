#include <bits/stdc++.h>
using namespace std;
static vector<int>count_num(9,0);
static inline void Reset();
static inline bool Cheak();
int main(){
    int n;
    cin >> n;
    vector<vector<int>>matrix(9,vector<int>(9));
    for(int t=0;t<n;t++){
        bool flag = false;
        for(int i=0;i<9;i++){
            Reset();
            for(int j=0;j<9;j++){
                cin >> matrix[i][j];
                if(!(1<=matrix[i][j] && matrix[i][j]<=9))flag = true;
                else count_num[matrix[i][j]-1]++;
            }
            if(!flag && Cheak())flag = true;
        }
        if(flag){
            cout << 00 << endl;
            continue;
        }
        for(int j=0;j<9;j++){
            Reset();
            for(int i=0;i<9;i++){
                count_num[matrix[i][j]-1]++;
            }
            if(Cheak()){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        for(int k = 0;k < 9;k++){
            Reset();
            for(int i=k%3*3;i<k%3*3+3;i++){
                for(int j=k/3*3;j<k/3*3+3;j++){
                    count_num[matrix[i][j]-1]++;
                }
            }
            if(Cheak()){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
    }
}
static inline void Reset(){
    for(int i=0;i<9;i++)count_num[i] = 0;
}
static inline bool Cheak(){
    for(int i=0;i<9;i++)if(count_num[i]!=1)return true;
    return false;
}