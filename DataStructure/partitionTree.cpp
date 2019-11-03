const int M=4e4+7,N=5e4+7;
ll n,m,q,T;
//http://acm.hdu.edu.cn/showproblem.php?pid=3966
//https://www.cnblogs.com/baocong/p/6745117.html
ll a[N];
int to[N<<1],nxt[N<<1],head[N],tot;
int ls[N<<2],rs[N<<2];
ll s[N<<2],laz[N<<2];
int siz[N],dep[N],fa[N],p[N],fp[N],son[N],top[N],tpos;
void init()
{
    mem(head,-1),tot=tpos=0;
    for(int i=0;i<N;i++)
        dep[i]=siz[i]=p[i]=fp[i]=fa[i]=son[i]=top[i]=0;
}
inline void addedge(int u,int v)
{
    to[tot]=v,nxt[tot]=head[u],head[u]=tot++;
    to[tot]=u,nxt[tot]=head[v],head[v]=tot++;
}
inline void up(int rt)
{
    s[rt]=s[rt<<1]+s[rt<<1|1];
}
inline void down(int rt)
{
    if(laz[rt]){
        ll len=rs[rt]-ls[rt]+1;
        s[rt<<1]+=laz[rt]*(len-(len>>1));
        s[rt<<1|1]+=laz[rt]*(len>>1);
        laz[rt<<1]+=laz[rt];
        laz[rt<<1|1]+=laz[rt];
        laz[rt]=0;
    }
}
void build(int rt,int l,int r)
{
    ls[rt]=l,rs[rt]=r,laz[rt]=0;
    if(l==r){ s[rt]=a[fp[l]];return;}
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    up(rt);
}
void update(int rt,int x,int y,ll v)
{
    if(x<=ls[rt]&&rs[rt]<=y){
        s[rt]+=v*(rs[rt]-ls[rt]+1);
        laz[rt]+=v;
        return;
    }
    down(rt);
    int mid=ls[rt]+rs[rt]>>1;
    if(x<=mid) update(rt<<1,x,y,v);
    if(y>mid) update(rt<<1|1,x,y,v);
    up(rt);
}
ll query(int rt,int x)
{
    if(ls[rt]==rs[rt]) return s[rt];
    down(rt);
    int mid=ls[rt]+rs[rt]>>1;
    if(x<=mid) return query(rt<<1,x);
    else return query(rt<<1|1,x);
}
void dfs1(int cur,int pre)
{
    siz[cur]=1;
    fa[cur]=pre;
    dep[cur]=dep[pre]+1;
    for(int i=head[cur];~i;i=nxt[i])if(to[i]!=pre){
        dfs1(to[i],cur);
        siz[cur]+=siz[to[i]];
        if(son[cur]==0||siz[to[i]]>siz[son[cur]])
            son[cur]=to[i];
    }
}
void dfs2(int cur,int tp)
{
    top[cur]=tp,p[cur]=++tpos,fp[tpos]=cur;
    if(son[cur]==0) return;
    dfs2(son[cur],tp);
    for(int i=head[cur];~i;i=nxt[i])if(to[i]!=son[cur]&&to[i]!=fa[cur])
        dfs2(to[i],to[i]);
}
void fix(int u,int v,ll val)
{
    int f1=top[u],f2=top[v];
    while(f1!=f2){
        if(dep[f1]<dep[f2])
            swap(f1,f2),swap(u,v);
        update(1,p[f1],p[u],val);
        u=fa[f1],f1=top[u];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(1,p[u],p[v],val);
}
int main()
{
    while(~scanf("%lld%lld%lld",&n,&m,&q)){
        init();
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=0,u,v;i<m;i++)
            read(u),read(v),addedge(u,v);
        dfs1(1,0);
        dfs2(1,1);
        build(1,1,n);
        int op,x,y;
        char ch[2];
        ll val;
        while(q--){
            scanf("%s",ch);
            if(ch[0]=='Q'){
                read(x),fuck(query(1,p[x]));
            }else if(ch[0]=='I'){
                read(x),read(y),read(val);
                fix(x,y,val);
            }else{
                read(x),read(y),read(val);
                fix(x,y,-val);
            }
        }
    }
 
    return 0;
}
/*******************************Sample**************************************
3 2 5
1 2 3
2 1
2 3
I 1 3 5
Q 2
D 1 2 2
Q 1
Q 3
 
7
4
8
****************************************************************************/
