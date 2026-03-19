#include <bits/stdc++.h>
using namespace std;
static inline bool could_find(vector<int> arr,int n);
static inline int position(vector<int> arr,int n);
bool a(int a,int b){
    return a>b;
}
int main(){
    string num;
    int i;
    vector<int>arr;
    vector<int>index(11);
    cin >> num;
    for(i=0;i<11;i++)
        if(!could_find(arr,num[i]-'0'))arr.push_back(num[i]-'0');
    sort(arr.begin(),arr.end(),a);
    for(i=0;i<11;i++){
        index[i] = position(arr,num[i]-'0');
    }
    cout << "int[] arr = new int[]{";
    for(i=0;i<arr.size()-1;i++)cout << arr[i] << ",";
    cout << arr[i] << "};" << endl;
    cout << "int[] index = new int[]{";
    for(i=0;i<index.size()-1;i++)cout << index[i] << ",";
    cout << index[i] << "};" << endl;
}
static inline bool could_find(vector<int> arr,int n){
    for(vector<int>::iterator it=arr.begin();it!=arr.end();it++)
        if(*it==n)return true;
    return false;
}
static inline int position(vector<int> arr,int n){
    int i;
    for(i=0;i<arr.size();i++){
        if(arr[i]==n)return i;
    }
}