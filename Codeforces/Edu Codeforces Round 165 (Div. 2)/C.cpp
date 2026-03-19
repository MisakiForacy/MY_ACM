#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N 300100
#define INF 0x3f3f3f3f
#define PI 3.141592653
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
struct info{
    string n;
    int a,b;
};
typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}*BinaryTree,BinaryNode;
vector<vector<int>>matrix;
vector<int>arr(N,0);
bool flag;
int maxn,minn,mini;
int a[N];
ll n,m,k,t;
ll d,i,j,s,res,datle,sum;
db f;
static inline bool cmp(const int &a,const int &b);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        minn = INF;
        mini = INF;
        maxn = -INF;
        m = 0;
        sum = 0;
        cin >> n >> k;
        for(i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
            if(a[i]<mini)mini = a[i];
        }
        if(k>=n)res = mini*n;
        else{
            for(i=0;i<n-k;i++){
                m = 0;
                minn = INF;
                for(j=i;j<=i+k;j++){
                    m += a[j];
                    if(a[j]<minn)minn = a[j];
                }
                datle = m-minn*(k+1);
                if(datle>maxn)maxn = datle;
            }
            res = sum - maxn;
        }
        cout << res << endl;
    }
}