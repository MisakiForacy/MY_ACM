#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static vector<int>Pre;
static vector<int>In_A;
static vector<int>In_B;

static inline bool cmp(int a,int b);
static inline void CreateBinaryTree_A(int root,int start,int end,BinaryTree &Tree);
static inline void CreateBinaryTree_B(int root,int start,int end,BinaryTree &Tree);
static inline void PostTraversal(BinaryTree Tree);

int main(){
    int n;
    cin >> n;
    Pre.resize(n);
    In_A.resize(n);
    In_B.resize(n);
    for(int i=0;i<n;i++){
        cin >> Pre[i];
        In_A[i] = Pre[i];
        In_B[i] = Pre[i];
    }
    sort(In_A.begin(),In_A.end());
    sort(In_B.begin(),In_B.end(),cmp);
    BinaryTree Tree_A,Tree_B;
    CreateBinaryTree_A(0,0,n-1,Tree_A);
    CreateBinaryTree_B(0,0,n-1,Tree_B);
    PostTraversal(Tree_A);
    cout << endl;
    PostTraversal(Tree_B);
    cout << endl;
    return 0;
}

static inline bool cmp(int a,int b){
    return a>b;
}

static inline void CreateBinaryTree_A(int root,int start,int end,BinaryTree &Tree){
    while(start>end){
        Tree = NULL;
        return;
    }
    int i=start;
    while(i<end && In_A[i]!=Pre[root])i++;
    Tree = new BinaryNode;
    CreateBinaryTree_A(root+1,start,i-1,Tree->lchild);
    CreateBinaryTree_A(root+(i-start+1),i+1,end,Tree->rchild);
    Tree->data = In_A[i];
}

static inline void CreateBinaryTree_B(int root,int start,int end,BinaryTree &Tree){
    while(start>end){
        Tree = NULL;
        return;
    }
    int i=start;
    while(i<end && In_B[i]!=Pre[root])i++;
    Tree = new BinaryNode;
    CreateBinaryTree_B(root+1,start,i-1,Tree->lchild);
    CreateBinaryTree_B(root+(i-start+1),i+1,end,Tree->rchild);
    Tree->data = In_B[i];
}

static inline void PostTraversal(BinaryTree Tree){
    if(Tree){
        PostTraversal(Tree->lchild);
        PostTraversal(Tree->rchild);
        cout << Tree->data << " ";
    }
}