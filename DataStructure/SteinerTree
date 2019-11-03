//n个点 m条边 求连通其中p个点的最小代价
const int maxm=1e5+7,maxn=55;
int maz[maxn][maxn],a[maxn],dp[(1<<10)+10][maxn];
int n,m,p;
int steiner()
{
    mem(maz,0),mem(dp,0x3f);
    for(int i=0,u,v,w;i<m;i++)
        read(u),read(v),read(w),maz[u][v]=maz[v][u]=w;
    for(int i=1;i<=n;i++) maz[i][0]=maz[0][i]=inf;
    for(int i=0,x,w;i<p;i++)
        read(x),read(w),a[i+1]=x,maz[0][x]=maz[x][0]=w;
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                maz[i][j]=min(maz[i][j],maz[i][k]+maz[k][j]);
    for(int i=1;i<=p;i++)
        for(int j=0;j<=n;j++)
            dp[1<<i-1][j]=maz[a[i]][j];
    for(int s=1;s<(1<<p);s++){
        if(s&(s-1)==0)
            continue;
        for(int i=0;i<=n;i++)
            for(int nxt=s;nxt;nxt=(nxt-1)&s)
                dp[s][i]=min(dp[s][i],dp[nxt][i]+dp[s-nxt][i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[s][i]=min(dp[s][i],dp[s][j]+maz[i][j]);
    }
    return dp[(1<<p)-1][0];
}
