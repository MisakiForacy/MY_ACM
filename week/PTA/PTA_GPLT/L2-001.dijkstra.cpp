#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <deque>
#include <cstdio>
#define INF 0x3f3f3f3f
#define N 600
using namespace std;
typedef long long ll;
typedef double db;

typedef struct RoadInformation{
    int begin;
    int end;
    int len;
} RI;


/*Dijkstra加权无向图最短路径搜索算法*/
int main(){
    int n,m,s,d;    //n:城市数，m:道路条数，s:出发地，d:目的地
    int i,j,k;
    bool flag;
    cin >> n >> m >> s >> d;
    vector<int>rescue(n);
    vector<RI>road(m);
    int roads[N][N];
    memset(roads,0x3f,sizeof(roads));
    vector<ll>D(n,INF);        //从原点到每一个节点的最短路径
    vector<int>P(n,0);         //原点到节点的路径向量（即 上一个节点的位置）
    vector<bool>Final(n,0);    //作为标记 表示是否为最短路径

    // for(i=0,cin >> rescue[i];i<n;i++)
    for(i=0;i<m;i++){
        cin >> road[i].begin >> road[i].end >> road[i].len;
        roads[road[i].begin][road[i].end] = roads[road[i].end][road[i].begin] = road[i].len;
    };
    D[s] = 0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            flag = true;
            for(j=0;j<n;j++){
                // if(Final[j])continue;
                if(min(D[j],D[i]+roads[i][j]) < D[j]){
                    D[j] = min(D[j],D[i]+roads[i][j]);
                    P[j] = i;
                    flag = false;
                }
            }
            if(flag){
                Final[i] = 1;
            }

            // for(z=0;z<n;z++){
            //     cout << D[z] << " ";
            // }cout << endl;
        }
    }
    for(i=0;i<n;i++)cout << D[i] << " ";cout << endl;
    for(i=0;i<n;i++)cout << P[i] << " ";cout << endl;
    cout << D[d];
}