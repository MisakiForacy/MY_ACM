#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s1,s2,s3,max=-INF,t;
    cin >> s1 >> s2 >> s3;
    vector<int>list(s1+s2+s3+1);
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                list[i+j+k]++;
            }
        }
    }
    for(int i=0;i<s1+s2+s3+1;i++){
        if(list[i]>max){
            max = list[i];
            t = i;
        }
    }
    cout << t;
    return 0;
}