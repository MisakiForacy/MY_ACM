#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
typedef double db;
using namespace std;
bool find(int x,vector<int> list){
    for(int i=0;i<list.size();i++){
        if(x==list[i])return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,num,count=0;
    cin >> n;
    vector<int>list(n);
    for(int i=0;i<n;i++){
        cin >> list[i];
    }
    for(int i=0;i<n;i++){
        num = list[i];
        for(int x=1;x<=num/2;x++){
            if(find(x,list)&find(num-x,list)&(x!=num-x)){
                count++;
                break;
            }
        }
    }
    cout << count;
    return 0;
}