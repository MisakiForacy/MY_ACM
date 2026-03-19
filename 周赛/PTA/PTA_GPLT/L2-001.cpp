// #include <bits/stdc++.h>
// #define INF 0x3f3f3f3f
// using namespace std;

// struct road{
//     int c1;
//     int c2;
//     int length;
// };

// struct roads{
//     vector<int>w;
//     int len=0;
//     int rescue=0;
// };

// int main(){
//     int N,M,S,D;
//     int i,j;
//     int minn = INF,maxn = -INF,count = 0,index = -1;
//     bool flag;
//     cin >> N >> M >> S >> D;
//     vector<int>R(N);
//     vector<road>list(M);
//     vector<roads>ways(M);
//     for(i=0;i<N;i++){
//         cin >> R[i];
//     }
//     for(i=0;i<M;i++){
//         cin >> list[i].c1 >> list[i].c2 >> list[i].length;
//     }
//     for(i=0;i<M;i++){
//         if(list[i].c1 == S){
//             ways[i].w.push_back(list[i].c1);
//             ways[i].w.push_back(list[i].c2);
//             ways[i].len += list[i].length;
//             ways[i].rescue += R[list[i].c1] + R[list[i].c2];
//             while(ways[i].w[ways[i].w.size()-1] != D){
//                 flag = true;
//                 for(j=0;j<M;j++){
//                     if(ways[i].w[ways[i].w.size()-1] == list[j].c1){
//                         ways[i].w.push_back(list[j].c2);
//                         ways[i].len += list[j].length;
//                         ways[i].rescue += R[list[j].c2];
//                         flag = false;
//                     }
//                 }
//                 if(flag)break;
//             }
//         }
//     }
//     for(i=0;i<M;i++){
//         if(ways[i].len!=0 && ways[i].len < minn && ways[i].w[ways[i].w.size()-1] == D){
//             minn = ways[i].len;
//             index = i;
//         }
//     }
//     for(i=0;i<M;i++){
//         if(ways[i].len == minn && ways[i].w[ways[i].w.size()-1] == D){
//             count++;
//             if(ways[i].rescue > maxn){
//                 maxn = ways[i].rescue;
//                 index = i;
//             }
//         }
//     }
//     cout << count << " " << maxn << endl;
//     int len = ways[index].w.size()-1;
//     for(i=0;i<len;i++){
//         cout << ways[index].w[i] << " ";
//     }
//     cout << ways[index].w[i] << endl;
//     return 0;
// }

#pragma once
#include <bits/stdc++.h>
#define N 10000
using namespace std;
int main(){
    int n,m,k;
    int i;
    
    cin >> n >> m >> k;
    for(i=0;i<n;i++){
        cin >> t[i];
    }

}