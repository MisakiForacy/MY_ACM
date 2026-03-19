#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}*BinaryTree, BinaryNode;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);
static inline void SequenceTraversal(BinaryTree Tree);

int main(){
    int n;
    cin >> n;
    vector<int>u(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> u[i] >> v[i];
    }
    for
}