#include <bits/stdc++.h>
using namespace std;
static inline bool BoxFull(vector<int>B,int m){return B.size()==m;}
static inline bool BrunchFull(vector<int>N,int k){return N.size()==k;}
static inline bool PusherNotEmpty(vector<int>T){return T.size();}
static inline void print(vector<int>N){
    int i;
    if(N.size()){
        for(i=0;i<N.size()-1;i++)cout << N[i] << " ";
        cout << N[i] << endl;
    }
    else{
        cout << "empty" << endl;
    }
}
int main(){
    int n,m,k;
    int s;
    int i;
    cin >> n >> m >> k;
    vector<int>T;
    vector<int>B;
    vector<int>N;
    for(i=0;i<n;i++){
        cin >> s;
        T.push_back(s);
    }
    while(B.size()!=0 || T.size()!=0){
        // cout << N.size() << T.size() << endl;
        if(!N.size()){              //松枝为空
            if(!B.size()){          //盒子为空
                s = T[0];           //取推送器最前松枝片
                T.erase(T.begin());
                N.push_back(s);     //插入松枝干最底下
            }
            else{                   //松枝不为空
                s = B[B.size()-1];  //取盒子最上面松枝片
                B.pop_back();
                N.push_back(s);     //插入松枝干最底下
            }
        }
        else{                       //松枝不为空
            if(!B.size()){          //盒子为空
                s = T[0];           //取推送器最前松枝片
                T.erase(T.begin());
                if(s <= N[N.size()-1]){  //松枝满足插上松枝干要求
                    N.push_back(s);      //插上松枝(需要判断)
                    if(BrunchFull(N,k)){
                        print(N);           //自底向上输出松枝片
                        N.clear();          //取新松枝
                        continue;
                    }
                }
                else{                   //松枝不满足插上松枝干要求
                    if(BoxFull(B,m)){        //盒子满
                        print(N);
                        N.clear();
                        continue;
                    }
                    else{               //盒子未满
                        B.push_back(s);
                    }
                }
            }
            else{           //盒子不为空
                s = B[B.size()-1];
                if(s <= N[N.size()-1]){
                    B.pop_back();
                    N.push_back(s);
                }
                else if(PusherNotEmpty(T)){
                    s = T[0];           //取推送器最前松枝片
                    T.erase(T.begin());
                    if(s <= N[N.size()-1]){  //松枝满足插上松枝干要求
                        N.push_back(s);      //插上松枝(需要判断)
                        if(BrunchFull(N,k)){
                            print(N);           //自底向上输出松枝片
                            N.clear();          //取新松枝
                            continue;
                        }
                    }
                    else{                   //松枝不满足插上松枝干要求
                        if(BoxFull(B,m)){        //盒子满
                            print(N);
                            N.clear();
                            T.insert(T.begin(),s);
                            continue;
                        }
                        else{               //盒子未满
                            B.push_back(s);
                        }
                    }
                }
                else if(!PusherNotEmpty(T)){
                    print(N);
                    N.clear();
                    continue;
                }
            }
        }
    }
    if(N.size())print(N);
    return 0;
}