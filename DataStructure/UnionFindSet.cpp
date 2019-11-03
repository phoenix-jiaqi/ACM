int f[maxn],depth[maxn],ans;//森林中节点最多的树的节点数
void init()
{
    for(int i=1;i<maxn;i++) f[i]=i,depth[i]=1;
    ans=1;
}
int fid(int x)
{
    int r=x,t;
    while(r!=f[r]) r=f[r];
    while(x!=r) t=f[x],f[x]=r,x=t;
    return r;
}
void combine(int a,int b)
{
    int fa=fid(a),fb=fid(b);
    if(fa!=fb)
        f[fa]=fb,depth[fb]+=depth[fa],ans=max(ans,depth[fb]);
}
