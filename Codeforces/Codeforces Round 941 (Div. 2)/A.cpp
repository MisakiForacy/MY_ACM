#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define N 100
#define INF 0x3f3f3f3f
#define PI 3.1415926
typedef long long ll;
typedef double db;
using namespace std;

int maxn = -INF;
ll n,m,t,k;
ll i,j;
ll a[N], b[N][N];

typedef struct Node_1{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

typedef struct Node_2 *MulityTree;
typedef struct Node_2{
    int data;
    vector<MulityTree>childs;
}*MultiyTree,MultiyNode;

static deque<BinaryTree>SequenceTraversal;
// static vector<int>num(N,0);
static vector<int>arr;
static vector<vector<int>>matrix1;
static vector<vector<int>>matrix2;

static inline bool cmp(int &a,int &b);
static inline void CreateBinaryTree(BinaryTree &Tree);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        maxn = -INF;
        int max_num = 0;
        cin >> n >> k;
        arr.resize(n);
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        for(i=0;i<n;i++){
            max_num=0;
            for(j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    max_num++;
                }
            }
            if(max_num>maxn)maxn=max_num;
        }
        if(maxn<k){
            cout << n << endl;
        }
        else{
            cout << k-1 << endl;
        }
    }
    return 0;
}