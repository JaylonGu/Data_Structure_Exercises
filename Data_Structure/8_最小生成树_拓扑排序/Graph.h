#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Graph{
protected:
    int nv;   //  number of vertices
    vector<string> vertices;
    map<string,int> iov;  // index of vertices
    bool directed;
    vector<bool> visited;
    virtual void dfs(int v)=0;
public:
//  创建图
    Graph(bool directed=false){
        this->directed=directed;
        nv=0;
    }
    Graph(int n, bool directed=false){
        this->directed=directed;
        nv=n;
        vertices.resize(n);
        for(int i=0;i<n;i++){
            vertices[i]=to_string(i);
            iov[to_string(i)]=i;
        }
    }
    Graph(vector<string> v, bool directed=false){
        this->directed=directed;
        nv=(int)v.size();   // v.size() returns unsigned int
        vertices=v;
        for(int i=0;i<nv;i++){
            iov[v[i]]=i;
        }
    }
//  插入节点
    virtual bool insertV(string v){
        if(iov.find(v) != iov.end()) return false;
        vertices.push_back(v);
        iov[v]=nv;
        nv++;
        return true;
    }
    virtual void insertV(){
        insertV(to_string(nv));
    }
//  插入边
    virtual bool insertE(int src, int dst, int weight=1)=0; // 不允许通过编号插入新点
    virtual bool insertE(string src, string dst, int weight=1){
        insertV(src);
        insertV(dst);
        return insertE(iov[src],iov[dst],weight);
    }
//  查找边

//  删除边
    virtual bool removeE(int src, int dst)=0;
    virtual bool removeE(string src, string dst){
        if(iov.find(src)==iov.end() || iov.find(dst)==iov.end()) return false;
        return removeE(iov[src],iov[dst]);
    }
//  DFS
    virtual void dfs(string v){
        if(iov.find(v)==iov.end()) return;
        visited.resize(nv);
        for(int i=0;i<nv;i++) visited[i]=false;
        dfs(iov[v]);
    }
//  BFS

};

class MGraph : public Graph{
protected:
    vector<vector<int> > adjM;
    void setAdjM(){
        adjM.resize(nv);
        for(int i=0;i<nv;i++){
            adjM[i].resize(nv);
            for(int j=0; i<nv; j++){
                adjM[i][j]=INT32_MAX;
            }
        }
    }
    void dfs(int v){
        cout<<vertices[v]<<" ";
        visited[v]=true;
        for(int i=0;i<nv;i++){
            if(!visited[i] && adjM[v][i]!=INT32_MAX) dfs(i);
        }
    }
public:
//  创建图
    MGraph(bool directed=false):Graph(directed){ }
    MGraph(vector<string> v, bool directed=false):Graph(v,directed){
        setAdjM();
    }
    MGraph(int n, bool directed=false):Graph(n,directed){
        setAdjM();
    }
//  插入节点
    bool insertV(string v){
        bool r=Graph::insertV(v);
        if(!r) return false;
        for(int i=0;i<nv-1;i++){
            adjM[i].push_back(INT32_MAX);
        }
        adjM.push_back(vector<int>(nv,INT32_MAX));
        return true;
    }
    void insertV(){
        insertV(to_string(nv));
    }
//  插入边
    bool insertE(int src, int dst, int weight=1){
        if(src<0 || dst<0 ||src>=nv || dst>=nv) return false;
        if(adjM[src][dst] != INT32_MAX) return false;
        adjM[src][dst]=weight;
        if(!directed) adjM[dst][src]=weight;
        return true;
    }
    bool insertE(string src, string dst, int weight=1){
        return Graph::insertE(src,dst,weight);
    }
//  查找边

//  删除边
    bool removeE(int src, int dst){
        if(src<0 || dst<0 ||src>=nv || dst>=nv) return false;
        if(adjM[src][dst]==INT32_MAX) return false;
        adjM[src][dst]==INT32_MAX;
        if(!directed) adjM[dst][src]==INT32_MAX;
        return true;
    }
    bool removeE(string src, string dst){
        return Graph::removeE(src,dst);
    }
//  DFS
    void dfs(string v){
        Graph::dfs(v);
    }
//  BFS
    void bfs(string v){
        if(iov.find(v)==iov.end()) return;
        visited.resize(nv);
        for(int i=0;i<nv;i++) visited[i]=false;
        queue<int> q;
        cout<< v << " ";
        int iv=iov[v];
        visited[iv]=true;
        q.push(iv);
        while(!q.empty()){
            int w=q.front();
            q.pop();
            for(int i=0;i<nv;i++){
                if(!visited[i] && adjM[w][i] != INT32_MAX){
                    cout<<vertices[i]<<" ";
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
};

class LGraph : public Graph{
protected:
    vector<map<int,int> > adjL;
    void setAdjL(){
        adjL.resize(nv);
        for(auto x : adjL) x.clear();
    }
    void dfs(int v){
        cout<<vertices[v]<<" ";
        visited[v]=true;
        for(auto x : adjL[v] ){
            if(!visited[x.first]) dfs(x.first);
        }
    }
public:
//  创建图
    LGraph(bool directed=false):Graph(directed){ }
    LGraph(vector<string> v, bool directed=false):Graph(v,directed){
        setAdjL();
    }
    LGraph(int n, bool directed=false):Graph(n,directed){
        setAdjL();
    }
//  插入节点
    bool insertV(string v){
        bool r=Graph::insertV(v);
        if(!r) return false;
        adjL.push_back(map<int,int>());
        return true;
    }
    void insertV(){
        insertV(to_string(nv));
    }
//  插入边
    bool insertE(int src, int dst, int weight=1){
        if(src<0 || dst<0 ||src>=nv || dst>=nv) return false;
        if(adjL[src].find(dst) != adjL[src].end()) return false;
        adjL[src].insert(pair<int,int>(dst,weight));
        if(!directed) adjL[dst].insert(pair<int,int>(src,weight));
        return true;
    }
    bool insertE(string src, string dst, int weight=1){
        return Graph::insertE(src,dst,weight);
    }
//  查找边

//  删除边
    bool removeE(int src, int dst){
        if(src<0 || dst<0 ||src>=nv || dst>=nv) return false;
        if(adjL[src].find(dst)==adjL[src].end()) return false;
        adjL[src].erase(dst);
        if(!directed) adjL[dst].erase(src);
        return true;
    }
    bool removeE(string src, string dst){
        return Graph::removeE(src,dst);
    }
//  DFS
    void dfs(string v){
        Graph::dfs(v);
    }
//  BFS
    void bfs(string v){
        if(iov.find(v)==iov.end()) return;
        visited.resize(nv);
        for(int i=0;i<nv;i++) visited[i]=false;
        queue<int> q;
        cout<< v << " ";
        int iv=iov[v];
        visited[iv]=true;
        q.push(iv);
        while(!q.empty()){
            int w=q.front();
            q.pop();
            for(auto x:adjL[w]){
                if(!visited[x.first]){
                    cout<<vertices[x.first]<<" ";
                    visited[x.first]=true;
                    q.push(x.first);
                }
            }
        }
    }
//  TopSort
    bool topSort(){
        vector<int> inDegree(nv,0);
        for(auto vl:adjL){
            for(auto w: vl)
                inDegree[w.first]++;
        }
        queue<int> q;
        for(int i=0;i<nv;i++)
            if(inDegree[i]==0) q.push(i);
        int count=0,v;
        while(!q.empty()){
            v.q.front();
            q.pop();
            cout<<vertices[v]<<" ";
            count++;
            for(auto w:adjL[v]){
                inDegree[w.first]--;
                if(inDegree[w.first]==0) q.push(w.first);
            }
        }
        if(count != nv) return false;
        else return true;
    }
};