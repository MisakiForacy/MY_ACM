#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N 1005
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
vector<int>arr;
int a[N];
ll n,m,k,t;
ll d,i,j,s;
db f;
static inline bool cmp(const int &a,const int &b);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
}