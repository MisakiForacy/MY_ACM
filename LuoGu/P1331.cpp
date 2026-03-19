#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
i64 r, c, cnt = 0;
// string line;
vector<vector<i64>>matrix;
void dfs(i64 y, i64 x);
bool cheak();
int main(){
    cin >> r >> c;
    matrix.resize(r + 2, vector<i64>(c + 2));
    for(int i = 0; i <= c + 1; i ++)
        matrix[0][i] = matrix[r + 1][i] = 0;
    for(int i = 0; i <= r + 1; i ++)
        matrix[i][0] = matrix[i][c + 1] = 0;
    for(int i = 1; i <= r; i ++){
        string line;
        cin >> line;
        for(int j = 1; j <= c; j ++){
            matrix[i][j] = (line[j - 1] == '#');
        }
    }
    // for(int i = 0; i <= r + 1; i ++){
    //     for(int j = 0; j <= c + 1; j ++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(cheak()){
        for(int i = 1; i <= r; i ++){
            for(int j = 1; j <= c; j ++){
                if(matrix[i][j]){
                    cnt ++;
                    dfs(i,j);
                }
            }
        }
        cout << "There are " << cnt << " ships." << endl;
    }
    else{
        cout << "Bad placement." << endl;
    }
}
bool cheak(){
    for(int i = 1; i < r; i ++){
        for(int j = 1; j < c; j ++){
            if(matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1] == 3){
                return false;
            }
        }
    }
    return true;
}
void dfs(i64 y, i64 x){
    matrix[y][x] = 0;
    for(int i = 0; i < 4; i ++){
        if(matrix[y + dy[i]][x + dx[i]]){
            dfs(y + dy[i], x + dx[i]);
        }
    }
}