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
static vector<int>va;
static vector<int>vb;
static deque<int>da;
static vector<vector<int>>matrix;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    int n;
    cin >> n;
    va.resize(n+1,0);
    int m = 0,h = 0;
    for(int i=1;i<=n;i++){
        cin >> va[i];
        m += va[i] - va[i-1];
        if(m>50)m = 50;
        if(m>=8)h += m/8, m = m%8;
    }
    cout << h << endl;
    return 0;
}