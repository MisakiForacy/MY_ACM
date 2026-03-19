#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}*BinaryTree,BinaryNode;

static vector<int>arr;
static vector<int>int_list_b;
static vector<db>db_list_a;
static vector<db>db_list_b;
static deque<int>SequenceTraversal;

static inline void CreateBinaryTree(BinaryTree *Tree);
static inline void PreTraversal(BinaryTree Tree);

int main(){
    int t,n,stick;
    cin >> t;
    while(t--){
        int res = 0,num;
        cin >> n;
        arr.resize(n);
        for(int i=0;i<n;i++)cin >> arr[i];
        if(n<=2){
            cout << 0 << endl;
            continue;
        }
        else{
            while(arr.size()){
                num = 1;
                stick = arr[0];
                arr.erase(arr.begin()+0);
                while(find(arr.begin(),arr.end(),stick)!=arr.end()){
                    num++;
                    arr.erase(find(arr.begin(),arr.end(),stick));
                }
                if(num > 2){
                    res += num/3;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}