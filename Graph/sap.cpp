/// HDU 3549

///--------------------------------isap & stack optimization ------------------------

struct Edge{
    int to,next,cap,flow;
}edge[maxn];
int tol,head[maxn],gap[maxn],dep[maxn],S[maxn],cur[maxn];
void init()
{
    tol=0,mem(head,-1);
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
    edge[tol].flow=0;head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
    edge[tol].flow=0;head[v]=tol++;
}
int Q[maxn];
void bfs(int st,int en)
{
    mem(dep,-1),mem(gap,0);
    gap[0]=1;
    int front=0,rear=0;
    dep[en]=0,Q[rear++]=en;
    while(front!=rear){
        int u=Q[front++];
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(dep[v]!=-1) continue;
            Q[rear++]=v;
            dep[v]=dep[u]+1;
            gap[dep[v]]++;
        }
    }
}
int sap(int st,int en,int N)
{
    bfs(st,en);
    memcpy(cur,head,sizeof(head));
    int top=0,u=st,ans=0;
    while(dep[st]<N){
        if(u==en){
            int Min=INF,inser;
            for(int i=0;i<top;i++)
                if(Min>edge[S[i]].cap-edge[S[i]].flow)
                    Min=edge[S[i]].cap-edge[S[i]].flow,inser=i;
            for(int i=0;i<top;i++)
                edge[S[i]].flow+=Min,edge[S[i]^1].flow-=Min;
            ans+=Min,top=inser,u=edge[S[top]^1].to;
            continue;
        }
        bool flag=false;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next){
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u]){
                flag=true,cur[u]=i;
                break;
            }
        }
        if(flag){
            S[top++]=cur[u];
            u=v;continue;
        }
        int Min=N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min)
                Min=dep[edge[i].to],cur[u]=i;
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u]=Min+1,gap[dep[u]]++;
        if(u!=st) u=edge[S[--top]^1].to;
    }
    return ans;
}


///------------------------------------------- isap --------------------------------

struct Edge{
    int to,next,cap,flow;
}edge[maxn];
int tol,head[maxn],gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init()
{
    tol=0,mem(head,-1);
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];
    edge[tol].flow=0;head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];
    edge[tol].flow=0;head[v]=tol++;
}
int sap(int st,int en,int N)
{
    mem(gap,0),mem(dep,0),memcpy(cur,head,sizeof(head));
    int u=st,ans=0;
    pre[u]=-1,gap[0]=N;
    while(dep[st]<N){
        if(u==en){
            int Min=INF;
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
                Min=min(Min,edge[i].cap-edge[i].flow);
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
                edge[i].flow+=Min,edge[i^1].flow-=Min;
            u=st,ans+=Min;
            continue;
        }
        bool flag=false;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next){
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u]){
                flag=true,cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag){
            u=v;continue;
        }
        int Min=N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min)
                Min=dep[edge[i].to],cur[u]=i;
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u]=Min+1,gap[dep[u]]++;
        if(u!=st) u=edge[pre[u]^1].to;
    }
    return ans;
}



///------------------------------------------- EdmondKarp-------------------------------------------

bool vis[maxn];
int maz[maxn][maxn],pre[maxn],ans;
int init()
{
    mem(maz,0),mem(vis,false),ans=0;
}
bool bfs(int st,int en)
{
    MST(pre,-1),MST(vis,false);
    pre[st]=st,vis[st]=true;
    int p,i;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        p=q.front(),q.pop();
        for(int i=0;i<=n;i++){
            if(!vis[i]&&maz[p][i]>0){
                pre[i]=p,vis[i]=true;
                if(i==en) return true;
                q.push(i);
            }
        }
    }
    return false;
}
int EdmonKarp(int st,int en)
{
    int mflow=0;
    while(bfs(st,en)){
        int t=INF;
        for(int i=en;i!=st;i=pre[i])
            t=min(t,maz[pre[i]][i]);
        for(int i=en;i!=st;i=pre[i])
            maz[pre[i]][i]-=t,maz[i][pre[i]]+=t;
        mflow+=t;
    }
    return mflow;
}
