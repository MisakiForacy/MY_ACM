#include <iostream>
#include <cstring>
#define N 100000
using namespace std;
struct LinkList{
    int value,ptr;
};
int main(){
    bool flag = true,newlist = false;
    int head,n;
    int i;
    int address,value,ptr,last_ptr,new_head,new_list_last_ptr;
    bool SavedValue[N];
    struct LinkList L[N];
    struct LinkList NewList[N];
    memset(SavedValue,0,sizeof(SavedValue));
    cin >> head >> n;
    for(i=0;i<n;i++){
        cin >> address >> value >> ptr;
        L[address].value = value;
        L[address].ptr = ptr;
    }
    ptr = head;
    new_head = -1;
    new_list_last_ptr = -1;
    while(flag){
        if(L[ptr].ptr == -1){
            flag = false;
        }
        if(SavedValue[abs(L[ptr].value)]){
            newlist = true;
            if(new_head == -1){
                new_head = ptr;
                NewList[ptr].value = L[ptr].value;
                NewList[ptr].ptr = -1;
                L[last_ptr].ptr = L[ptr].ptr;
                new_list_last_ptr = ptr;
            }
            else{
                NewList[new_list_last_ptr].ptr = ptr;
                NewList[ptr].value = L[ptr].value;
                NewList[ptr].ptr = -1;
                L[last_ptr].ptr = L[ptr].ptr;
                new_list_last_ptr = ptr;
            }
        }
        else{
            SavedValue[abs(L[ptr].value)] = 1;
            last_ptr = ptr;
        }
        ptr = L[ptr].ptr;
    }
    flag = true;
    ptr = head;
    while(flag){
        if(L[ptr].ptr == -1){
            flag = false;
        }
        if(L[ptr].ptr!=-1)printf("%05d %d %05d\n",ptr,L[ptr].value,L[ptr].ptr);
        else printf("%05d %d -1\n",ptr,L[ptr].value);
        ptr = L[ptr].ptr;
    }
    flag = true;
    ptr = new_head;
    while(flag && newlist){
        if(NewList[ptr].ptr == -1){
            flag = false;
        }
        if(NewList[ptr].ptr!=-1)printf("%05d %d %05d\n",ptr,NewList[ptr],NewList[ptr].ptr);
        else printf("%05d %d -1\n",ptr,NewList[ptr].value);
        ptr = NewList[ptr].ptr;
    }
}