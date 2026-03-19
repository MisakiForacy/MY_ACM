#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,S,L;
    if(!(cin>>N>>S>>L)) return 0;
    int M,K,P;
    cin>>M>>K>>P;

    int blockSpines = S / P;
    int blockOXCs = M / P;
    int R = N * blockSpines * K;

    // OXC port mapping, persistent across queries
    vector<vector<int>> oxc(M, vector<int>(R, -1));

    for(int qi=0; qi<5; ++qi){
        int Q; cin>>Q;
        struct Flow{int gA,a,gB,b;};
        vector<Flow> flows(Q);
        for(int i=0;i<Q;++i) cin>>flows[i].gA>>flows[i].a>>flows[i].gB>>flows[i].b;

        // store chosen routes
        vector<array<int,5>> routes(Q);
        
        // save current topology before this query
        vector<vector<int>> prevOxc = oxc;

        for(int i=0;i<Q;++i){
            int gA = flows[i].gA, gB = flows[i].gB;
            bool placed = false;
            
            // try all OXCs
            for(int m=0; m<M && !placed; ++m){
                int p = m / blockOXCs; // plane index
                
                // Spines in the same plane as OXC m
                int spineStart = p * blockSpines;
                int spineEnd = min((p + 1) * blockSpines, (int)S);
                
                // try to find two free (or matching) ports
                for(int spineX = spineStart; spineX < spineEnd && !placed; ++spineX){
                    for(int k1=0; k1<K && !placed; ++k1){
                        for(int spineY = spineStart; spineY < spineEnd && !placed; ++spineY){
                            for(int k2=0; k2<K && !placed; ++k2){
                                // Port mapping: i⋅(S/P)⋅K+(j mod(S/P))⋅K+k
                                // where i is group, j is spine in the plane, k is link
                                int portX = gA * blockSpines * K + (spineX % blockSpines) * K + k1;
                                int portY = gB * blockSpines * K + (spineY % blockSpines) * K + k2;
                                
                                if(portX<0 || portX>=R || portY<0 || portY>=R) continue;
                                
                                // Check if ports are free or already connected to each other
                                bool portX_free = (oxc[m][portX] == -1);
                                bool portY_free = (oxc[m][portY] == -1);
                                bool already_paired = (oxc[m][portX] == portY && oxc[m][portY] == portX);
                                
                                if(portX_free && portY_free){
                                    // Both free, make connection
                                    oxc[m][portX] = portY;
                                    oxc[m][portY] = portX;
                                    
                                    routes[i] = {spineX, k1, m, spineY, k2};
                                    placed = true;
                                } else if(already_paired){
                                    // Already connected, reuse
                                    routes[i] = {spineX, k1, m, spineY, k2};
                                    placed = true;
                                }
                            }
                        }
                    }
                }
            }
            
            if(!placed){
                // Fallback: force allocation, possibly overwriting
                for(int m=0; m<M && !placed; ++m){
                    int p = m / blockOXCs;
                    int spineStart = p * blockSpines;
                    int spineEnd = min((p + 1) * blockSpines, (int)S);
                    
                    for(int spineX = spineStart; spineX < spineEnd && !placed; ++spineX){
                        for(int k1=0;k1<K && !placed;++k1){ 
                            for(int spineY = spineStart; spineY < spineEnd && !placed; ++spineY){
                                for(int k2=0;k2<K && !placed;++k2){
                                    int portX = gA * blockSpines * K + (spineX % blockSpines) * K + k1;
                                    int portY = gB * blockSpines * K + (spineY % blockSpines) * K + k2;
                                    
                                    if(portX<0 || portX>=R || portY<0 || portY>=R) continue;
                                    
                                    // Force disconnect and reconnect
                                    if(oxc[m][portX] != -1 && oxc[m][portX] != portY){
                                        int other = oxc[m][portX];
                                        oxc[m][other] = -1;
                                    }
                                    if(oxc[m][portY] != -1 && oxc[m][portY] != portX){
                                        int other = oxc[m][portY];
                                        oxc[m][other] = -1;
                                    }
                                    
                                    oxc[m][portX] = portY;
                                    oxc[m][portY] = portX;
                                    
                                    routes[i] = {spineX, k1, m, spineY, k2};
                                    placed = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        // output current OXC topologies
        for(int m=0;m<M;++m){
            for(int j=0;j<R;++j){
                if(j) cout<<' ';
                cout<<oxc[m][j];
            }
            cout<<"\n";
        }

        // output routes
        for(int i=0;i<Q;++i){
            auto &r = routes[i];
            cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<" "<<r[4]<<"\n";
        }
    }

    return 0;
}