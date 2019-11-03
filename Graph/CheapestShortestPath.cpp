struct HeapNode{ //优先队列的节点
    int d,u,c;
    bool operator<(const HeapNode& rhs)const{
        if(d==rhs.d) return c>rhs.c;
        return d>rhs.d;
    }
};
 
struct Edge{ //建图的边
    int from,to,dist,cost;
    Edge(int u,int v,int d,int c):from(u),to(v),dist(d),cost(c){}
};
 
struct Dijkstra{
    int n,m;
    vector<Edge>edges;//边
    vector<int>G[maxn];//存储边的编号
    bool done[maxn];//是否已永久标记
    int d[maxn];//dist距离
    int c[maxn];//cost花费
    int p[maxn];//上一条
 
    void init(int n){
        this->n=n;//this->m=m;
        for(int i=0;i<=n;++i) G[i].clear();
        edges.clear();
    }
 
    void AddEdge(int from,int to,int dist,int cost){
        edges.push_back(Edge(from,to,dist,cost));
        m=edges.size();
        G[from].push_back(m-1);
    }
 
    void dijkstra(int s){
        priority_queue<HeapNode>Q;
        for(int i=0;i<=n;i++) d[i]=inf;
        d[s]=0,c[s]=0;
        mem(done,0);
        Q.push((HeapNode){0,s,0});
        while(!Q.empty()){
            HeapNode x = Q.top(); Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[u].size();++i ){
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist ||(d[e.to]==d[u]+e.dist&&c[e.to]>c[u]+e.cost) ){
                    d[e.to]=d[u]+e.dist;
                    c[e.to]=c[u]+e.cost;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to,c[e.to]} );
                }
            }
        }
    }
 
};
Dijkstra dij;
//dij.init(n);
//a--,b--,s--,t--;
//dij.AddEdge(a,b,Dis,Cost);
//dij.dijkstra(s);
//ll mdis=dij.d[t],mcost=dij.c[t];
