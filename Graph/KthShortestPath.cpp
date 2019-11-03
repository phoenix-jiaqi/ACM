int s,e,k,t;
int head[M],to[M],nxt[M],tot;
int rhead[M],rto[M],rnxt[M],rtot;
int val[M];
void init()
{
    mem(head,-1),tot=0;
    mem(rhead,-1),rtot=0;
}
inline void addedge(int u,int v,ll ww)
{
    to[tot]=v,val[tot]=ww,nxt[tot]=head[u],head[u]=tot++;
    rto[rtot]=u,val[rtot]=ww,rnxt[rtot]=rhead[v],rhead[v]=rtot++;
}
int dis[N];
bool vis[N];
void spfa(int st)
{
    mem(dis,inf);dis[st]=0;
    mem(vis,false);
    queue<int> q;
    q.push(st);
    vis[st]=true;
    int u,v;
    int ww;
    while(!q.empty()){
        u=q.front(),q.pop();
        vis[u]=false;
        for(int i=rhead[u];~i;i=rnxt[i]){
            v=rto[i];
            ww=val[i];
            if(dis[v]>dis[u]+ww){
                dis[v]=dis[u]+ww;
                if(!vis[v])
                    q.push(v),vis[v]=true;
            }
        }
    }
}
struct A{
    int f,g,id;
    bool operator<(const A &b)const{
        if(f==b.f) return g>b.g;
        return f>b.f;
    }
};
int A_star(int st,int en)
{
    int cnt=0,u,v,gg,ff;
    priority_queue<A> q;
    if(st==en) k++;
    if(dis[st]==inf) return -1;
    q.push(A{dis[st],0,st});
    A tp;
    while(!q.empty()){
        tp=q.top(),q.pop();
        if(tp.id==en){
            cnt++;
            if(cnt==k)
                return tp.f;
        }
        for(int i=head[tp.id];~i;i=nxt[i]){
            v=to[i];
            gg=tp.g+val[i];
            ff=gg+dis[v];
            q.push(A{ff,gg,v});
        }
    }
    return -1;
}
