//HDOJ 2586
 
const int M=20,N=4e4+7;
ll n,m,T;
 
int head[N<<1],nxt[N<<1],to[N<<1],w[N<<1],tot;
int fa[N][M],dep[N],dp[N];
void init()
{
    mem(head,-1),mem(dp,0),tot=0;
}
inline void addedge(int u,int v,int ww)
{
    to[tot]=v,w[tot]=ww,nxt[tot]=head[u],head[u]=tot++;
    to[tot]=u,w[tot]=ww,nxt[tot]=head[v],head[v]=tot++;
}
void dfs(int cur,int pre)
{
    dep[cur]=dep[pre]+1;
    for(int i=1;i<M;i++)
        fa[cur][i]=fa[fa[cur][i-1]][i-1];
    for(int i=head[cur];~i;i=nxt[i])if(to[i]!=pre)
        fa[to[i]][0]=cur,dp[to[i]]=dp[cur]+w[i],dfs(to[i],cur);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int len=dep[x]-dep[y];
    for(int i=0;i<M;i++)
        if((len>>i)&1) x=fa[x][i];
    if(x==y) return x;
    for(int i=M-1;i>=0;i--)if(fa[x][i]!=fa[y][i])
        x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main()
{
    read(T);while(T--){
        read(n),read(m);init();
        for(int i=1,x,y,z;i<n;i++) read(x),read(y),read(z),addedge(x,y,z);
        dfs(1,0);
        int x,y,cfa;
        while(m--){
            read(x),read(y),cfa=lca(x,y);
            fuck(dp[x]+dp[y]-(dp[cfa]<<1));
        }
    }
    return 0;
}
/*******************************Sample**************************************
Sample Input
 
2
 
3 2
1 2 10
3 1 15
1 2
2 3
 
2 2
1 2 100
1 2
2 1
 
Sample Output
 
10
25
100
100
 
****************************************************************************/
