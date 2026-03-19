#include <bits/stdc++.h>
using namespace std;
struct info{
    int num;
    bool flag;
}a[] = {0,0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0};
int main(){
    int x1,y1,x2,y2,x3,y3,direction;
    int ii,jj;
    int i,j;
    int score = 0;
    map<int,int>mm = {
        {6,10000},{7,36},{8,720},{9,360},{10,80},
        {11,252},{12,108},{13,72},{14,54},{15,180},
        {16,72},{17,180},{18,119},{19,36},{20,306},
        {21,1080},{22,144},{23,1800},{24,3600}
    };
    vector<vector<int>>list(3,vector<int>(3));
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> list[i][j];
            if(list[i][j]==0){
                ii = i;
                jj = j;
            }
            else{
                a[list[i][j]].flag = 1;
            }
        }
    }
    for(i=1;i<=9;i++){
        if(a[i].flag == 0){
            list[ii][jj] = a[i].num;
            break;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> direction; 
    cout << list[x1-1][y1-1] << endl << list[x2-1][y2-1] << endl << list[x3-1][y3-1] << endl;
    if(direction == 1)score = list[0][0] + list[0][1] + list[0][2];
    else if(direction == 2)score = list[1][0] + list[1][1] + list[1][2];
    else if(direction == 3)score = list[2][0] + list[2][1] + list[2][2];
    else if(direction == 4)score = list[0][0] + list[1][0] + list[2][0];
    else if(direction == 5)score = list[0][1] + list[1][1] + list[2][1];
    else if(direction == 6)score = list[0][2] + list[1][2] + list[2][2];
    else if(direction == 7)score = list[0][0] + list[1][1] + list[2][2];
    else if(direction == 8)score = list[0][2] + list[1][1] + list[2][0];
    cout << mm[score] << endl;
}