int head[N],tot,to[M],nxt[M];
ll w[M],dis[N];
bool vis[N];
struct node{
    int u;
    ll val;
    bool operator<(const node& rhs)const{
        return val>rhs.val;
    }
};
priority_queue<node> q;
void init()
{
    mem(head,-1),tot=0;
    mem(vis,false);
    mem(dis,inf);
    while(!q.empty()) q.pop();
}
void addedge(int u,int v,ll z)
{
    to[tot]=v,w[tot]=z,nxt[tot]=head[u],head[u]=tot++;
}
void dijkstra(int s)
{
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
        node cur=q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];~i;i=nxt[i]){
            int v=to[i],z=w[i];
            if(dis[v]>dis[u]+z){
                dis[v]=dis[u]+z;
                q.push({v,dis[v]});
            }
        }
    }
}
