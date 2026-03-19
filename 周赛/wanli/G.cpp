#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
static inline bool cmp_x(const node &a,const node &b){
    return a.x<b.x;
}
static inline bool cmp_y(const node &a,const node &b){
    return a.y<b.y;
}
int main(){
    int t;
    bool flag;
    cin >> t;
    char cx;int x,y;
    while(t--){
        flag = true;
        vector<node>coord(5);
        for(int i=0;i<5;i++){
            cin >> cx >> y;
            x = cx - 'A',y-=1;
            coord[i].x = x , coord[i].y = y;
        }
        sort(coord.begin(),coord.end(),cmp_x);
        // for(int i=0;i<5;i++)cout << coord[i].x << " ";cout << endl;
        for(int i=1;i<5;i++){
            if(coord[i].y != coord[0].y || coord[i].x - coord[i-1].x != 1){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            continue;
        }
        flag = true;
        sort(coord.begin(),coord.end(),cmp_y);
        for(int i=1;i<5;i++){
            if(coord[i].x != coord[0].x || coord[i].y - coord[i-1].y != 1){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            continue;
        }
        flag = true;
        sort(coord.begin(),coord.end(),cmp_x);
        for(int i=1;i<5;i++){
            if(coord[i].y - coord[i-1].y != -1 || coord[i].x - coord[i-1].x != 1){
                // cout << coord[i].x << ":" << coord[i-1].x << ":" << coord[i].y << ":" << coord[i-1].y << endl;
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            continue;
        }
        flag = true;
        for(int i=1;i<5;i++){
            if(coord[i].y - coord[i-1].y != 1 || coord[i].x - coord[i-1].x != 1){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}