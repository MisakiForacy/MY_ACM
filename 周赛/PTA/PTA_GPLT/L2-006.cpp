#include <bits/stdc++.h>
using namespace std;
static vector<int>In;
static vector<int>Post;
typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;
deque<BinaryTree>q1;
vector<int>q2;
void CreateBinaryTree(int root,int start,int end,BinaryTree &Tree){
    if(start>end){
        Tree = NULL;
        return;
    }
    int i = start;
    while(i<end && In[i]!=Post[root])i++;
    Tree = new BinaryNode;
    Tree->data = In[i];
    CreateBinaryTree(root - (end-i+1),start,i-1,Tree->lchild);
    CreateBinaryTree(root - 1,i+1,end,Tree->rchild);
}
void SequenceTraversal(BinaryTree Tree){
    q1.push_back(Tree);
    while(q1.size()){
        Tree = q1[0];
        q1.pop_front();
        q2.push_back(Tree->data);
        if(Tree->lchild)q1.push_back(Tree->lchild);
        if(Tree->rchild)q1.push_back(Tree->rchild);
    }
}
int main(){
    int n;
    cin >> n;
    In.resize(n);
    Post.resize(n);
    for(int i=0;i<n;i++)cin >> Post[i];
    for(int i=0;i<n;i++)cin >> In[i];
    BinaryTree Tree;
    CreateBinaryTree(n-1,0,n-1,Tree);
    SequenceTraversal(Tree);
    int i;
    for(i=0;i<q2.size()-1;i++){
        cout << q2[i] << " ";
    }cout << q2[i] << endl;
    return 0;
}