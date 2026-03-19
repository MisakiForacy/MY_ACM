#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static vector<char>root;
static vector<vector<int>>node;
static inline void CreateBinaryTree(BinaryTree &Tree,char c);
static inline  int CountNode(BinaryTree Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    int n;
    cin >> n;
    node.resize(n+1,vector<int>(3,-1));
    root.resize(n);
    string line;
    int leaf = 0;
    for(int i=1;i<=n;i++){
        cin >> line;
        root[i-1] = line[0];
        node[i][0] = line[0];
        node[i][1] = line[1];
        node[i][2] = line[2];
        if(line[1] == '*')leaf++;
        if(line[2] == '*')leaf++;
    }
    BinaryTree Tree;
    int node = n + leaf;
    for(auto c : root){
        CreateBinaryTree(Tree,c);
        if(CountNode(Tree) == node){
            break;
        }
    }
    PreTraversal(Tree);
    return 0;
}

static inline void CreateBinaryTree(BinaryTree &Tree,char c){
    if(c == '*'){
        Tree = NULL;
        return;
    }
    Tree = new BinaryNode;
    Tree->data = c;
    CreateBinaryTree(Tree->lchild,node[find(root.begin(),root.end(),c)-root.begin()+1][1]);
    CreateBinaryTree(Tree->rchild,node[find(root.begin(),root.end(),c)-root.begin()+1][2]);
}

static inline int CountNode(BinaryTree Tree){
    if(Tree){
        return CountNode(Tree->lchild) + CountNode(Tree->rchild) + 1;
    }
    else return 1;
}

static inline void PreTraversal(BinaryTree Tree){
    if(Tree){
        cout << Tree->data;
        PreTraversal(Tree->lchild);
        PreTraversal(Tree->rchild);
    }
}