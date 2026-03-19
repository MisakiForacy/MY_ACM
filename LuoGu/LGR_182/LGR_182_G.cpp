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
    int n,m;
    cin >> n >> m;
    matrix.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    int l,x,score = 0;
    for(int i=0;i<n;i++){
        cin >> l;
        int po = 0;
        for(int j=0;j<l;j++){
            cin >> x;
            if(find(matrix[i].begin(),matrix[i].end(),x)!=matrix[i].end()){
                po++;
            }
        }
        if(po == m){
            score += 2;
        }
    }
    cout << score << endl;
    return 0;
}