#include <bits/stdc++.h>
using namespace std;
// typedef struct Node{
//     char data;
//     struct Node *lchild,*rchild;
// }*BinaryTree,BinaryNode;

static vector<char>Pre;
static vector<char>In;

static inline void CreateBinaryTree(int root,int start,int end);

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    for(int i=0;i<s1.length();i++)In.push_back(s1[i]);
    for(int i=0;i<s2.length();i++)Pre.push_back(s2[i]);
    CreateBinaryTree(0,0,Pre.size()-1);
    return 0;
}

static inline void CreateBinaryTree(int root,int start,int end){
    if(start > end)return;
    int i = start;
    while(i<end && Pre[root] != In[i])i++;
    // Tree = new BinaryNode;
    CreateBinaryTree(root+1,start,i-1);
    CreateBinaryTree(root+(i-start+1),i+1,end);
    cout << In[i];
}