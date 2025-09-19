#include <bits/stdc++.h>
#define endl '\n'
#define N 100000
#define inf (i64)0x3f3f3f3f3f3f3f3f3f
using namespace std;
typedef long long i64;
typedef double llf;
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*LinkedList, LinkedNode;
void InitLinkedList(LinkedList &List);
void InsertFront(LinkedList &List,LinkedNode *node);
void InsertBack(LinkedList &List,LinkedNode *node);
int main(){

}
void InitLinkedList(LinkedList &List){
    List->next = NULL;
    List->prev = NULL;
    List->data = -1;
}
void InsertFront(LinkedList &List,LinkedNode *node){
    if(!List->next){
        node->next = NULL;
        node->prev = List;
        List->next = node;
    }
    else{
        List->next->prev = node;
        node->next = List->next;
        node->prev = List;
        List->next = node;
    }
}
void InsertBack(LinkedList &List,LinkedNode *node){
    LinkedNode *last = List; 
    while(last->next)last = last->next;
    node->next = NULL;
    last->next = node;
    node->prev = last;
}