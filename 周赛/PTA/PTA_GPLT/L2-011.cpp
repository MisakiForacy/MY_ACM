#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static deque<BinaryTree>q1;
static vector<int>q;
static vector<int>pre;
static vector<int>in;

static inline void CreateBinaryTree(int root,int start,int end,BinaryTree &Tree);
static inline void SequenceReserveTraversal(BinaryTree Tree);
static inline void PostOrderTraversal(BinaryTree Tree);

int main(){
    int n,i;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    BinaryTree Tree;
    for(i=0;i<n;i++)cin >> in[i];
    for(i=0;i<n;i++)cin >> pre[i];
    CreateBinaryTree(0,0,n-1,Tree);
    // PostOrderTraversal(Tree);
    // cout << endl;
    SequenceReserveTraversal(Tree);
    for(i=0;i<q.size()-1;i++)cout << q[i] << " ";
    cout << q[i] << endl;
    return 0;
}

static inline void CreateBinaryTree(int root,int start,int end,BinaryTree &Tree){
    if(start>end){
        Tree = NULL;
        return;
    }
    int i = start;
    while(i<end && in[i]!=pre[root])i++;
    Tree = new BinaryNode;
    CreateBinaryTree(root+1,start,i-1,Tree->lchild);
    CreateBinaryTree(root+(i-start+1),i+1,end,Tree->rchild);
    Tree->data = in[i];
}

static inline void PostOrderTraversal(BinaryTree Tree){
    if(Tree){
        PostOrderTraversal(Tree->lchild);
        PostOrderTraversal(Tree->rchild);
        cout << Tree->data << "->";
    }
}

static inline void SequenceReserveTraversal(BinaryTree Tree){
    q1.push_back(Tree);
    while(q1.size()){
        Tree = q1[0];
        q1.pop_front();
        q.push_back(Tree->data);
        if(Tree->rchild)q1.push_back(Tree->rchild);
        if(Tree->lchild)q1.push_back(Tree->lchild);
    }
}
