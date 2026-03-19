#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 100010
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static int a[N];
static vector<ll>va;
static vector<int>vb;
static deque<int>da;
static vector<vector<int>>matrix;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    int maxn = -INF , minn = INF;
    int n;
    cin >> n;
    va.resize(n);
    for(int i=0;i<n;i++){
        cin >> va[i];
        if(va[i]>maxn)maxn = va[i];
        if(va[i]<minn)minn = va[i];
    }
    cout << minn + maxn << endl;
}