#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{int u,v;int w;};

bool read_input(const string &infile, int &n, int &m, ll &k){
    ifstream fin(infile);
    if(!fin) return false;
    if(!(fin>>n>>m>>k)) return false;
    return true;
}

string readTokenTrim(ifstream &f){
    string s;
    while(f>>s){
        if(!s.empty()) return s;
    }
    return string();
}

// validate an output file: returns pair(valid, message). If valid, mstSum set to MST sum; if output is "NO" then returns special flag 'NO'.
int validate_output(const string &outfile, int n, int m, ll k, ll &mstSum, string &msg){
    ifstream fo(outfile);
    if(!fo){ msg = "cannot open output"; return -1; }
    string tok;
    if(!(fo>>tok)){ msg = "empty output"; return -1; }
    if(tok=="NO"){
        // output says impossible
        return 0; // code 0 indicates NO
    }
    if(tok!="YES"){ msg = "first token not YES/NO"; return -1; }
    vector<Edge> edges;
    edges.reserve(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        if(!(fo>>u>>v>>w)) { msg = "not enough edges"; return -1; }
        edges.push_back({u,v,w});
    }
    // extra tokens are ignored
    // validate edges
    if((int)edges.size()!=m){ msg = "edge count mismatch"; return -1; }
    for(auto &e: edges){
        if(e.u<1 || e.u>n || e.v<1 || e.v>n){ msg = "vertex out of range"; return -1; }
        if(e.u==e.v){ msg = "self loop"; return -1; }
    }
    // check multiedges
    set<pair<int,int>> se;
    for(auto &e: edges){
        int a=min(e.u,e.v), b=max(e.u,e.v);
        if(se.count({a,b})){ msg = "multiple edge"; return -1; }
        se.insert({a,b});
    }
    // check weights unique and in [1,m]
    vector<int> usedw(m+1,0);
    for(auto &e: edges){
        if(e.w<1 || e.w>m){ msg = "weight out of range"; return -1; }
        if(usedw[e.w]){ msg = "duplicate weight"; return -1; }
        usedw[e.w]=1;
    }
    // compute MST using Kruskal
    vector<Edge> es = edges;
    sort(es.begin(), es.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });
    vector<int> p(n+1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> findp = [&](int x){ return p[x]==x?x:p[x]=findp(p[x]); };
    ll sum = 0; int cnt=0;
    for(auto &e: es){
        int fu=findp(e.u), fv=findp(e.v);
        if(fu!=fv){ p[fu]=fv; sum += e.w; cnt++; if(cnt==n-1) break; }
    }
    if(cnt!=n-1){ msg = "not connected"; return -1; }
    mstSum = sum;
    if(mstSum != k){ msg = "mst sum not equal"; return -1; }
    msg = "OK";
    return 1; // valid graph
}

int main(int argc, char** argv){
    if(argc<4){ cerr<<"Usage: spj <input> <outA> <outB>\n"; return 2; }
    string infile = argv[1];
    string outA = argv[2];
    string outB = argv[3];
    int n,m; ll k;
    if(!read_input(infile,n,m,k)){ cerr<<"bad input file\n"; return 2; }
    ll sumA=0,sumB=0; string msgA, msgB;
    int resA = validate_output(outA, n, m, k, sumA, msgA);
    int resB = validate_output(outB, n, m, k, sumB, msgB);
    // res code meanings: -1 invalid, 0 NO, 1 valid graph
    if(resA==0 && resB==0){ // both NO
        cout<<"both NO\n";
        return 0;
    }
    if(resA==0 && resB!=0){ cout<<"A:NO but B!=NO -> B expected valid\n"; return 3; }
    if(resB==0 && resA!=0){ cout<<"B:NO but A!=NO -> A expected valid\n"; return 4; }
    if(resA==1 && resB==1){ // both valid graphs
        cout<<"both valid\n";
        return 0;
    }
    // otherwise report
    if(resA==-1 && resB==1){ cout<<"A invalid: "<<msgA<<"\n"; return 5; }
    if(resB==-1 && resA==1){ cout<<"B invalid: "<<msgB<<"\n"; return 6; }
    if(resA==-1 && resB==-1){ cout<<"both invalid: A="<<msgA<<" B="<<msgB<<"\n"; return 7; }
    // fallback
    cout<<"unknown case A="<<resA<<" B="<<resB<<"\n";
    return 8;
}
