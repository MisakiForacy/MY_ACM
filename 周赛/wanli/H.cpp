#include <bits/stdc++.h>
using namespace std;
static inline void print(vector<vector<char>>matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
int main(){
    int n,h,w;
    int mid, top, spacel, spacer;
    int weight = 0;
    cin >> n;
    h = pow(2,n) + (n+1)%2;
    w = pow(2,n+1);
    mid = w / 2;
    top = 0;
    vector<vector<char>>matrix(h,vector<char>(w,' '));
    while(n>0){
        if(n%2){
            spacel = h-1;
            spacer = 0;
            for(int i=top; i<top + h; i++){
                matrix[i][mid - w/2 + spacel] = '/';
                matrix[i][mid + spacer] = '\\';
                spacel--, spacer++;
            }
            for(int j=mid - w/2 + 1;j < mid + w/2 -1;j++){
                matrix[top + h - 1][j] = '_';
            }
            top += pow(2,n-1)-1;
            weight++;
        }
        else{
            spacel = 0;
            spacer = h-1;
            for(int j=mid - w/2 + 1;j < mid + w/2 -1;j++){
                matrix[top][j] = '_';
            }
            for(int i=top+1; i<top + h; i++){
                matrix[i][mid - w/2 + spacel] = '\\';
                matrix[i][mid + spacer - 1] = '/';
                spacel++, spacer--;
            }
            top += 1;
            weight++;
        }
        n--;
        h = pow(2,n) + (n+1)%2;
        w = pow(2,n+1);
    }
    print(matrix);
}