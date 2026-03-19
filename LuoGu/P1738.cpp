// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

typedef struct Node *MultiTree;
typedef struct Node{
    string folderName;
    vector<MultiTree> child;
}*MultiTree, MultiNode;

int t, folder_num;
static vector<deque<string>>Paths;
static inline void CreateMultiTree(MultiTree &Tree);
static inline void AddMultiTree(MultiTree &Tree);
static inline int CountNode(MultiTree Tree);

int main(){
    int n;
    string path;
    int i,j,jj;
    cin >> n;
    Paths.resize(n);
    Paths[0].push_back("root");
    for(i=0;i<n;i++){
        cin >> path;
        jj = 1;
        for(j=1;j<path.length();j++){
            if(path[j]=='/'){
                Paths[i].push_back(path.substr(jj,j-jj));
                jj = j + 1;
            }
        }
        Paths[i].push_back(path.substr(jj,path.length()-jj+1));
    }
    MultiTree Tree = NULL;
    CreateMultiTree(Tree);
    CountNode(Tree);
    cout << folder_num-1 << endl;
    folder_num = 0;
    for(t=1;t<n;t++){
        AddMultiTree(Tree);
        CountNode(Tree);
        cout << folder_num-1 << endl;
        folder_num = 0;
    }
}

static inline void CreateMultiTree(MultiTree &Tree){
    if(!Paths[t].size()){
        Tree = NULL;
    }
    else{
        Tree = new MultiNode;
        Tree->folderName = Paths[t][0];
        Tree->child.resize(Tree->child.size()+1);
        Paths[t].pop_front();
        CreateMultiTree(Tree->child[Tree->child.size()-1]);
    }
}

static inline void AddMultiTree(MultiTree &Tree){
    int i;
    if(!Paths[t].size()){
        return;
    }
    for(i=0;i<Tree->child.size();i++){
        if(Tree->child[i] && Tree->child[i]->folderName == Paths[t][0]){
            Paths[t].pop_front();
            break;
        }
    }
    if(i!=Tree->child.size()){
        AddMultiTree(Tree->child[i]);
    }
    else{
        Tree->child.resize(Tree->child.size()+1);
        CreateMultiTree(Tree->child[Tree->child.size()-1]);
    }
}

static inline int CountNode(MultiTree Tree){
    if(Tree){
        folder_num++;
        for(int i=0;i<Tree->child.size();i++){
            folder_num += CountNode(Tree->child[i]);
        }
        return 0;
    }
    else return 0;
}