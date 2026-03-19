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

static int a[N];
static vector<int>va;
static vector<int>vb;
static deque<int>da;
static vector<vector<int>>matrix;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    string n;
    cin >> n;
    int A,B,C,D;
    A = 0,B = 0,C = 0,D = 0;
    for(int i=0;i<4;i++){
        if(n[i]=='A')A++;
        else if(n[i]=='B')B++;
        else if(n[i]=='C')C++;
        else if(n[i]=='D')D++;
    }
    if(D)cout << "Never give up." << endl;
    else if(C || B==4)cout << "This is ok." << endl;
    else if(A)cout << "I'm so happy." << endl;
    return 0;
}