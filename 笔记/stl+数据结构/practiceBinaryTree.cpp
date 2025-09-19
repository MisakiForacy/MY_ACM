#include <bits/stdc++.h>
#define INF (ll)0x3f3f3f3f3f3f3f3f
#define N 100000
using namespace std;
typedef long long ll;
typedef double db;

typedef struct Node{
    char data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

deque<BinaryTree>SequenceQueue;
vector<int>Pre;
vector<int>In;
vector<int>Post;
vector<int>Path;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void InPreCreateBinaryTree(int root,int start,int end,BinaryTree &Tree);
static inline void InPostCreateBinaryTree(int root,int start,int end,BinaryTree &Tree);
static inline void PreOrderTraversal(BinaryTree Tree);
static inline void InOrderTraversal(BinaryTree Tree);
static inline void PostOrderTraversal(BinaryTree Tree);
static inline void SequenceTraversal(BinaryTree Tree);
static inline void Traversal(BinaryTree Tree);
static inline void Copy(BinaryTree &Tree,BinaryTree &NewTree);
static inline void PrintBinaryTree(BinaryTree Tree);
static inline bool BinaryTreeEmpty(BinaryTree Tree);
static inline int CountNode(BinaryTree Tree);
static inline int CountLeafNode(BinaryTree Tree);
static inline int Depth(BinaryTree Tree);

int main(){
    BinaryTree Tree_1;
    BinaryTree Tree_2;
    BinaryTree Tree_3;
    BinaryTree Tree_4;
    cout << 1 << '\n';
    CreateBinaryTree(Tree_1);
    cout << 1 << '\n';
    Traversal(Tree_1);
    printf("%d %d %d\n",CountNode(Tree_1),CountLeafNode(Tree_1),Depth(Tree_1));
    int n;
    cin >> n;
    Pre.resize(n);
    In.resize(n);
    Post.resize(n);
    for(int i=0;i<n;i++)cin >> Pre[i];
    for(int i=0;i<n;i++)cin >> In[i];
    for(int i=0;i<n;i++)cin >> Post[i];
    InPreCreateBinaryTree(0,0,n-1,Tree_2);
    Traversal(Tree_2);
    printf("%d %d %d\n",CountNode(Tree_2),CountLeafNode(Tree_2),Depth(Tree_2));
    InPostCreateBinaryTree(n-1,0,n-1,Tree_3);
    Traversal(Tree_3);
    printf("%d %d %d\n",CountNode(Tree_3),CountLeafNode(Tree_3),Depth(Tree_3));
    Copy(Tree_1,Tree_4);
    Traversal(Tree_4);
    printf("%d %d %d\n",CountNode(Tree_4),CountLeafNode(Tree_4),Depth(Tree_4));
    cout << endl;
    PrintBinaryTree(Tree_4);
    return 0;
}

static inline void CreateBinaryTree(BinaryTree &Tree){
    char data;
    cin >> data;
    if(data=='0'){
        Tree = NULL;
    }
    else{
        Tree = new BinaryNode;
        Tree->data = data;
        CreateBinaryTree(Tree->lchild);
        CreateBinaryTree(Tree->rchild);
    }
}

static inline void InPreCreateBinaryTree(int root,int start,int end,BinaryTree &Tree){
    if(start>end){
        Tree = NULL;
        return;
    }
    int i=start;
    while(i<end && In[i]!=Pre[root])i++;
    Tree = new BinaryNode;
    InPreCreateBinaryTree(root+1,start,i-1,Tree->lchild);
    InPreCreateBinaryTree(root+(i-start+1),i+1,end,Tree->rchild);
    Tree->data = In[i];
}

static inline void InPostCreateBinaryTree(int root,int start,int end,BinaryTree &Tree){
    if(start>end){
        Tree = NULL;
        return;
    }
    int i=start;
    while(i<end && In[i]!=Post[root])i++;
    Tree = new BinaryNode;
    Tree->data = In[i];
    InPostCreateBinaryTree(root-(end-i+1),start,i-1,Tree->lchild);
    InPostCreateBinaryTree(root-1,i+1,end,Tree->rchild);
}

static inline void PreOrderTraversal(BinaryTree Tree){
    if(Tree){
        cout << Tree->data << "->";
        PreOrderTraversal(Tree->lchild);
        PreOrderTraversal(Tree->rchild);
    }
}

static inline void InOrderTraversal(BinaryTree Tree){
    if(Tree){
        InOrderTraversal(Tree->lchild);
        cout << Tree->data << "->";
        InOrderTraversal(Tree->rchild);
    }
}

static inline void PostOrderTraversal(BinaryTree Tree){
    if(Tree){
        PostOrderTraversal(Tree->lchild);
        PostOrderTraversal(Tree->rchild);
        cout << Tree->data << "->";
    }
}

static inline void SequenceTraversal(BinaryTree Tree){
    SequenceQueue.clear();
    SequenceQueue.push_back(Tree);
    while(SequenceQueue.size()){
        Tree = SequenceQueue[0];
        cout << Tree->data << "->";
        SequenceQueue.pop_front();
        if(Tree->lchild)SequenceQueue.push_back(Tree->lchild);
        if(Tree->rchild)SequenceQueue.push_back(Tree->rchild);
    }
}

static inline void Traversal(BinaryTree Tree){
    PreOrderTraversal(Tree);
    cout << endl;
    InOrderTraversal(Tree);
    cout << endl;
    PostOrderTraversal(Tree);
    cout << endl;
    SequenceTraversal(Tree);
    cout << endl;
}

static inline int CountNode(BinaryTree Tree){
    if(Tree){
        return CountNode(Tree->lchild) + CountNode(Tree->rchild) + 1;
    }
    else return 0;
}

static inline int CountLeafNode(BinaryTree Tree){
    if(!Tree){
        return 0;
    }
    else if(!Tree->lchild && !Tree->rchild){
        return 1;
    }
    else return CountLeafNode(Tree->lchild) + CountLeafNode(Tree->rchild);
}

static inline int Depth(BinaryTree Tree){
    if(Tree){
        int l = Depth(Tree->lchild);
        int r = Depth(Tree->rchild);
        return l > r ? l+1 : r+1;
    }
    else return 0;
}

static inline void Copy(BinaryTree &Tree,BinaryTree &NewTree){
    if(Tree){
        NewTree = new BinaryNode;
        NewTree->data = Tree->data;
        Copy(Tree->lchild,NewTree->lchild);
        Copy(Tree->rchild,NewTree->rchild);
    }
    else{
        NewTree = NULL;
        return;
    }
}

static inline bool BinaryTreeEmpty(BinaryTree Tree){
    if(Tree){
        return true;
    }
    else return false;
}

static inline void PrintBinaryTree(BinaryTree Tree){
    if(Tree){
        Path.push_back(Tree->data);
        if(Tree->lchild == NULL && Tree->rchild == NULL){
            for(int i=Path.size()-1;i> -1;i--){
                cout << Path[i] << " ";
            }cout << endl;
        }
        else{
            PrintBinaryTree(Tree->lchild);
            PrintBinaryTree(Tree->rchild);
        }
    }
}