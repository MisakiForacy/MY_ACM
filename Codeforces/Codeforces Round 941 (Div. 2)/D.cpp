#include <bits/stdc++.h>
#define N 1005
#define INF 0x3f3f3f3f
#define PI 3.1415926
typedef long long ll;
typedef double db;
using namespace std;

int n,i,j,k;
int a[N], b[N][N];

typedef struct Node_1{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

typedef struct Node_2 *MulityTree;
typedef struct Node_2{
    int data;
    vector<MulityTree>childs;
}*MultiyTree,MultiyNode;

static deque<BinaryTree>SequenceTraversal;
static vector<int>arr1;
static vector<int>arr2;
static vector<vector<int>>matrix1;
static vector<vector<int>>matrix2;

static inline bool cmp(int &a,int &b);
static inline void CreateBinaryTree(BinaryTree &Tree);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
}