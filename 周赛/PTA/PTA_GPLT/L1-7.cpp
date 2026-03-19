#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct info{
        int id;
        int couple;
        int d;
};
static vector<int>ID(100000,-1);
int main(){
    int n,m,x,a,b;
    cin >> n;
    vector<info>list;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        ID[a] = b,ID[b] = a;
    }
    cin >> m;
    list.resize(m);
    for(int i=0;i<m;i++){
        cin >> x;
        list[i].id = x;
        list[i].couple = -1;
        for(int j=0;j<i;j++){
            if(list[j].id == ID[list[i].id]){
                list[j].couple = ID[list[j].id];
                list[i].couple = ID[list[i].id];
            }
        }
    }
    for(int i=0;i<m;i++){
        if(list[i].couple >= 0){
            int index = -1;
            for(int j=i+1;j<m;j++){
                if(list[j].id == list[i].couple){
                    index = j;
                    break;
                }
            }
            if(index>i){
                if(index==i+1){
                    if(i-1>=0 && list[i-1].couple==-1)list[i-1].d++;
                    if(index+1<m && list[index+1].couple==-1)list[index+1].d++;
                }
                else{
                    for(int j=i+1;j<index;j++){
                        if(list[j].couple==-1)list[j].d++;
                    }
                }
            }
        }
    }
    int maxn = -INF;
    for(int i=0;i<m;i++){
            if(list[i].d > maxn)maxn = list[i].d;
    }
    vector<int>output;
    for(int i=0;i<m;i++){
        if(list[i].d == maxn)output.push_back(list[i].id);
    }
    sort(output.begin(),output.end());
    int len = output.size();
    for(int i=0;i<len-1;i++){
        printf("%05d ",output[i]);
    }printf("%05d",output[output.size()-1]);
    return 0;
}