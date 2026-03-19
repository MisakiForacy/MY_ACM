#include<iostream>
#include<map>
#include<vector>
#define int long long
using namespace std;
struct node{
    int t,x1,x2,x3,x4;
    char c;
};
signed main(){
    int n;cin>>n;
    vector<node>v;
    while(n--){
        string s;cin>>s;
        if(s=="Circle"){
            int x,y,r;char c;
            cin>>x>>y>>r>>c;
            v.push_back({1,x,y,r,0,c});
        }else if(s=="Rectangle"){
            int x1,y1,x2,y2;char c;
            cin>>x1>>y1>>x2>>y2>>c;
            v.push_back({2,x1,y1,x2,y2,c});
        }else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            for(int j=y2;j>=y1;j--){
                for(int i=x1;i<=x2;i++){
                    char p='.';
                    for(int k=v.size()-1;k>=0;k--){
                        if(v[k].t==1){
                            if((i-v[k].x1)*(i-v[k].x1)+(j-v[k].x2)*(j-v[k].x2)<=v[k].x3*v[k].x3){
                                p=v[k].c;
                                break;
                            }
                        }else{
                            if(i>=v[k].x1&&i<=v[k].x3&&j>=v[k].x2&&j<=v[k].x4){
                                p=v[k].c;
                                break;
                            }
                        }
                    }
                    cout<<p;
                }
                cout<<'\n';
            }
        }
    }
}
/*

.....*.....
..*******..
.**@***@**.
.*@@@*@@@*.
.**@***@**.
*****^*****
.****^****.
.**_____**.
.*********.
..*******..
.....*.....


@*@
***
*^*


*/