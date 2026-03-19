#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static vector<vector<int>>List;
static vector<int>Function;
static vector<int>LeafInput;
static int p;

static inline void CreateBinaryTree(BinaryTree &Tree,int p);
static inline void Reset(BinaryTree &Tree,BinaryTree &NewTree);
static inline bool FindTree(BinaryTree &Tree,int p,int num);
static inline int CountNode(BinaryTree Tree);
static inline bool Res(BinaryTree &CalTree);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n;
    vector<BinaryTree>node(n+1);
    List.resize(n+1,vector<int>(3,-1));
    Function.resize(n+1);
    List[0][0] = 0;
    int node_num = n , leaf = 0;
    for(int i=1;i<=n;i++){
        int fun;
        cin >> fun;
        Function[i] = fun;
        if(fun == 1){
            List[i][0] = i;
            cin >> List[i][1] >> List[i][2];
            if(!List[i][1])leaf++;
            if(!List[i][2])leaf++;
        }
        else if(fun == 2){
            List[i][0] = i;
            cin >> List[i][1] >> List[i][2];
            if(!List[i][1])leaf++;
            if(!List[i][2])leaf++;
        }
        else{
            List[i][0] = i;
            cin >> List[i][1];
            if(!List[i][1])leaf++;
        }
    }
    node_num = node_num + leaf;
    BinaryTree Tree , CalTree;
    for(int i=1;i<=n;i++){
        if(FindTree(Tree,i,node_num)){
            break;
        }
    }   
    string line;
    LeafInput.resize(leaf);
    cin >> k;
    for(int i=0;i<k;i++){
        Reset(Tree,CalTree);
        cin >> line;
        for(int j=0;j<leaf;j++){
            LeafInput[j] = line[j] - '0';
        }
        cout << (Res(CalTree)?"Ai":"BuAi") << endl;
        p = 0;
    }
    return 0;
}

static inline void CreateBinaryTree(BinaryTree &Tree,int p){
    if(p == -1){
        Tree = NULL;
        return;
    }
    Tree = new BinaryNode;
    Tree->data = List[p][0];
    CreateBinaryTree(Tree->lchild,List[p][1]);
    CreateBinaryTree(Tree->rchild,List[p][2]);
}

static inline void Reset(BinaryTree &Tree,BinaryTree &NewTree){
    if(Tree){
        NewTree = new BinaryNode;
        NewTree->data = Tree->data;
        Reset(Tree->lchild,NewTree->lchild);
        Reset(Tree->rchild,NewTree->rchild);
    }
    else{
        NewTree = NULL;
        return;
    }
}

static inline bool FindTree(BinaryTree &Tree,int p,int num){
    CreateBinaryTree(Tree,p);
    if(CountNode(Tree) == num)return true;
    return false;
}

static inline int CountNode(BinaryTree Tree){
    if(Tree)return CountNode(Tree->lchild) + CountNode(Tree->rchild) + 1;
    else return 0;
}

static inline bool Res(BinaryTree &CalTree){
    if(CalTree->lchild && !CalTree->rchild){
        return !Res(CalTree->lchild);
    }
    else if(CalTree->lchild && CalTree->rchild){
        if(Function[CalTree->data] == 1){
            return Res(CalTree->lchild) & Res(CalTree->rchild);
        }
        else if(Function[CalTree->data] == 2){
            return Res(CalTree->lchild) | Res(CalTree->rchild);
        }
    }
    else if(!CalTree->lchild && !CalTree->rchild){    
        return LeafInput[p++];
    }
}
