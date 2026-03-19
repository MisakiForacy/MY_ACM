#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

vector<vector<int>>node;
static inline void CreateBinaryTree(BinaryTree &Tree,int p);
static inline int CountNode(BinaryTree Tree);
static inline int Depth(BinaryTree Tree);

int main(){
    int n,l,r;
    cin >> n;
    node.resize(n+1,vector<int>(3,-1));
    int leaf = 0;
    for(int i=1;i<=n;i++){
        cin >> l >> r;
        node[i][0] = i+1;
        node[i][1] = l;
        node[i][2] = r;
        if(!l)leaf++;
        if(!r)leaf++;
    }
    int node_num = n + leaf;
    BinaryTree Tree;
    for(int i=1;i<=n;i++){
        CreateBinaryTree(Tree,i);
        if(CountNode(Tree) == node_num){
            break;
        }
    }
    cout << Depth(Tree) << endl;
    return 0;
}

static inline void CreateBinaryTree(BinaryTree &Tree,int p){
    if(p == 0){
        Tree = NULL;
        return;
    }
    Tree = new BinaryNode;
    Tree->data = node[p][0];
    CreateBinaryTree(Tree->lchild,node[p][1]);
    CreateBinaryTree(Tree->rchild,node[p][2]);
}

static inline int CountNode(BinaryTree Tree){
    if(Tree){
        return CountNode(Tree->lchild) + CountNode(Tree->rchild) + 1;
    }
    else return 1;
}

static inline int Depth(BinaryTree Tree){
    if(Tree){
        int l = Depth(Tree->lchild);
        int r = Depth(Tree->rchild);
        return l > r ? l + 1 : r + 1;
    }
    else return 0;
}
