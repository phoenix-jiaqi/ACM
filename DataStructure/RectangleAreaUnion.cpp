const int M=3e6+7,N=1e3+7;
int T,m,n;
 
struct seg{
    int l,r,h,v;
    bool operator<(const seg &rhs)const{
        return h<rhs.h;
    }
}s[N<<1];
int x[N<<1],cnt[N<<4],len[N<<4];
void up(int rt,int l,int r)
{
    if(cnt[rt])
        len[rt]=x[r]-x[l];
    else if(r<l)
        len[rt]=0;
    else
        len[rt]=len[rt<<1]+len[rt<<1|1];
}
void update(int rt,int l,int r,int x,int y,int v)
{
    if(x<=l&&r<=y){
        cnt[rt]+=v,up(rt,l,r);
        return;
    }
    int mid=l+r>>1;
    if(x<mid) update(rt<<1,l,mid,x,y,v);
    if(y>mid) update(rt<<1|1,mid,r,x,y,v);
    up(rt,l,r);
}
 
int ans;
int main()
{
    while(~scanf("%d",&n)&&n){
        for(int i=0,a,b,c,d;i<n;i++){
            read(a),read(b),read(c),read(d);
            s[i]=seg{a,c,b,1};
            s[i+n]=seg{a,c,d,-1};
            x[i]=a;
            x[i+n]=c;
        }
        n<<=1;
        sort(s,s+n);sort(x,x+n);
        mem(len,0);mem(cnt,0);
        m=unique(x,x+n)-x;
        ans=0;
        for(int i=0,l,r;i<n-1;i++){
            l=lower_bound(x,x+m,s[i].l)-x;
            r=lower_bound(x,x+m,s[i].r)-x;
            update(1,0,m,l,r,s[i].v);
            ans+=len[1]*(s[i+1].h-s[i].h);
        }
        fuck(ans);
    }
    return 0;
}
