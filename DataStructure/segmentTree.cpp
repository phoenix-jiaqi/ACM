ll a[N];
int ls[N<<2],rs[N<<2];
ll s[N<<2],laz[N<<2];
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
    if(l==r){ s[rt]=a[l];return;}
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
ll query(int rt,int x,int y)
{
    if(x<=ls[rt]&&rs[rt]<=y) return s[rt];
    down(rt);
    int mid=ls[rt]+rs[rt]>>1;
    ll res=0;
    if(x<=mid) res+=query(rt<<1,x);
    if(y>mid) res+=query(rt<<1|1,x);
    return res;
}
