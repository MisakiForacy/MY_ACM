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
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>num(n,0);
    for(int i=0;i<n;i++)cin >> arr[i],num[arr[i]-1]++;
    for(int i=0;i<n;i++){
        if(num[i] != 1 || arr[arr[i]-1]!=i+1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}