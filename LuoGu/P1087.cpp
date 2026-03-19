#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}*BinaryTree, BinaryNode;

static inline char Change(string s);
static inline void CreateBinaryTree(BinaryTree &Tree,string s);
static inline void PostTraversal(BinaryTree Tree);

int main(){
    int n;
    string s;
    BinaryTree Tree;
    cin >> n;
    cin >> s;
    CreateBinaryTree(Tree,s);
    PostTraversal(Tree);
    return 0;
}

static inline char Change(string s){
    int len = s.length();
    if(len != 1){
        if(s.find('1')!=-1 && s.find('0')!=-1) return 'F';
        else if(s.find('1')!=-1) return 'I';
        else return 'B';
    }
    if(s=="1")return 'I';
    else return 'B';
}

static inline void CreateBinaryTree(BinaryTree &Tree,string s){
    if(s.length()==0){
        Tree = NULL;
        return;
    }
    Tree = new BinaryNode;
    Tree->data = Change(s);
    // s.substr(s.length()/2,s.length()/2);
    CreateBinaryTree(Tree->lchild,s.substr(0,s.length()/2));
    CreateBinaryTree(Tree->rchild,s.substr(s.length()/2,s.length()/2));
}

static inline void PostTraversal(BinaryTree Tree){
    if(Tree){
        PostTraversal(Tree->lchild);
        PostTraversal(Tree->rchild);
        cout << Tree->data;
    }
}