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
static vector<int>alpha(26,0);
static vector<int>vb;
static deque<int>da;
static vector<vector<int>>matrix;

static inline void CreateBinaryTree(BinaryTree &Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    string str,cut;
    int res = 0;
    cin >> str;
    int i,j,len = str.length();
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            cut = "";
            for(int k=i;k<=j;k++){
                cut.push_back(str[k]);
            }
            for(int k=0;k<26;k++)alpha[k] = 0;
            for(int k=0;k<cut.length();k++){
                alpha[cut[k]-'a']++;
            }
            int maxn = alpha[0];
            // cout << alpha[0] << " :" << endl;
            for(int k=1;k<26;k++){
                if(alpha[k]>maxn)maxn = alpha[k];
            }
            // cout << maxn << cut << cut.length()/2 << endl;
            if(maxn<=(cut.length()/2)){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}