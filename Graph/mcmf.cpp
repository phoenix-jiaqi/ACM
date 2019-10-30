int flow[M],cap[M],to[M],nxt[M],head[M],tot;
bool vis[N];
ll cost[M],dis[N];
int pre[N];
void init()
{
    tot=0,mem(head,-1);
}
inline void addedge(int u,int v,int cp,ll ct)
{
    to[tot]=v,cap[tot]=cp,cost[tot]=ct,flow[tot]=0,nxt[tot]=head[u],head[u]=tot++;
    to[tot]=u,cap[tot]=0,cost[tot]=-ct,flow[tot]=0,nxt[tot]=head[v],head[v]=tot++;
}
bool spfa(int s,int t)
{
    queue<int> q;
    for(int i=0;i<nn;i++)   //nn==num of node
        dis[i]=inf,vis[i]=false,pre[i]=-1;
    dis[s]=0,vis[s]=true;
    int u,v;
    q.push(s);while(!q.empty()){
        u=q.front();q.pop();vis[u]=false;
        for(int i=head[u];~i;i=nxt[i]){
            v=to[i];
            if(cap[i]>flow[i]&&dis[v]>dis[u]+cost[i]){
                dis[v]=dis[u]+cost[i];
                pre[v]=i;
                if(!vis[v])
                    vis[v]=true,q.push(v);
            }
        }
    }
    return ~pre[t];
}
void MCMF(int s,int t)
{
    int fw=0,mn;
    ll ans=0;
    while(spfa(s,t)){
        mn=0x3f3f3f3f;
        for(int i=pre[t];~i;i=pre[to[i^1]])
            mn=min(mn,cap[i]-flow[i]);
        for(int i=pre[t];~i;i=pre[to[i^1]])
            flow[i]+=mn,flow[i^1]-=mn,ans+=cost[i];
        fw+=mn;
    }
    //fuck(fw);
    //fuck(ans);
}
