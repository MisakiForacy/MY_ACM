#include <bits/stdc++.h>
using namespace std;
const vector<int>a1 = {1,3,5,7,8,10,12};
const vector<int>a2 = {4,6,9,11};
// static inline bool Check(int x,int y);
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x==2 || y==2){
            cout << "No" << endl;
            continue;
        }
        else{
            if(find(a1.begin(),a1.end(),x)!=a1.end()){
                if(find(a1.begin(),a1.end(),y)!=a1.end()){
                    cout << "Yes" << endl;
                    continue;
                }
                cout << "No" << endl;
                continue;
            }
            else{
                if(find(a2.begin(),a2.end(),y)!=a2.end()){
                    cout << "Yes" << endl;
                    continue;
                }
                cout << "No" << endl;
                continue;
            }
        }
    }
    return 0;
}
