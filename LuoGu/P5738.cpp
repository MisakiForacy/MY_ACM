#include <iostream>
#include <vector>
#include <iomanip>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
static inline double aver(vector<int> list){
    double sum=0;
    for(vector<int>::iterator it=list.begin();it!=list.end();it++)sum+=*it;
    return sum/(list.size()-2);
}
int main(){
    int n,m,max=-INF,min=INF,maxi,mini;
    double M=-INF;
    cin >> n >> m;
    vector<vector<int>>a(n,vector<int>(m));
    vector<double>score;
    for(int i=0;i<n;i++){
        max=-INF,min=INF;
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]>max)max=a[i][j],maxi=j;
        }
        for(int j=0;j<m;j++)if(a[i][j]<min&&j!=maxi)min=a[i][j],mini=j;
        a[i][maxi] = 0;a[i][mini] = 0;
        score.push_back(aver(a[i]));
    }
    for(vector<double>::iterator it=score.begin();it!=score.end();it++)if(*it>M)M=*it;
    cout << fixed << setprecision(2) << M << endl;
    return 0;
}