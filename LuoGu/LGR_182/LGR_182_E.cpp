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

struct info{
    int h = INF;
    int c = 0;
};


// static vector<vector<info>>matrix;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<info>>matrix;
    matrix.resize(n,vector<info>(m));
    int x,y,h,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j].c = 0;
            matrix[i][j].h = INF;
        }
    }
    for(int i=0;i<k;i++){
        cin >> x >> y >> h >> c;
        x--,y--;
        if(matrix[x][y].h > h){
            matrix[x][y].h = h;
            matrix[x][y].c = c;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j].c << " ";
        }
        cout << endl;
    }
}