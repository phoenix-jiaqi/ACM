#include<bits/stdc++.h>
using namespace std;
#define MAXN 131072
#define ll long long
#define P 23333
struct node
{
    int a,b,c;
}t[MAXN<<1];
int n,q,m,N,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN],l[MAXN],r[MAXN],v[MAXN],a[MAXN],M[MAXN<<1];
void dfs(int x)
{
    v[l[x]=++N]=x;
    for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
    {
        f[p[i]]=x;
        dfs(p[i]);
    }
    r[x]=N;
}
void get(int R,int x)
{
    t[R].c=(t[R].c+2LL*x*t[R].b+(ll)x*x*t[R].a)%P;
    t[R].b=(t[R].b+(ll)x*t[R].a)%P;
    M[R]=(M[R]+x)%P;
}
void down(int R)
{
    if(M[R])
    {
        get(R<<1,M[R]);
        get(R<<1|1,M[R]);
        M[R]=0;
    }
}
void up(int R)
{
    t[R].a=(t[R<<1].a+t[R<<1|1].a)%P;
    t[R].b=(t[R<<1].b+t[R<<1|1].b)%P;
    t[R].c=(t[R<<1].c+t[R<<1|1].c)%P;
}
void build(int R,int l,int r)
{
    if(l==r)
    {
        t[R].a=1;
        t[R].b=a[v[l]]%P;
        t[R].c=(ll)a[v[l]]*a[v[l]]%P;
        return;
    }
    int mid=l+r>>1;
    build(R<<1,l,mid);
    build(R<<1|1,mid+1,r);
    up(R);
}
void fix(int R,int l,int r,int l1,int r1,int x)
{
    if(l1<=l&&r<=r1)
    {
        get(R,x);
        return;
    }
    down(R);
    int mid=l+r>>1;
    if(l1<=mid)fix(R<<1,l,mid,l1,r1,x);
    if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,x);
    up(R);
}
int ask(int R,int l,int r,int l1,int r1)
{
    if(l1==l&&r1==r)return t[R].c;
    down(R);
    int mid=l+r>>1;
    if(r1<=mid)return ask(R<<1,l,mid,l1,r1);
    if(l1>mid)return ask(R<<1|1,mid+1,r,l1,r1);
    return (ask(R<<1,l,mid,l1,mid)+ask(R<<1|1,mid+1,r,mid+1,r1))%P;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        p[++m]=k;
        ne[m]=h[j];
        h[j]=m;
        p[++m]=j;
        ne[m]=h[k];
        h[k]=m;
    }
    dfs(1);
    build(1,1,n);
    while(q--)
    {
        scanf("%d%d",&i,&j);
        if(i==1)
        {
            scanf("%d",&k);
            fix(1,1,n,l[j],r[j],k%P);
        }
        else printf("%d\n",ask(1,1,n,l[j],r[j]));
    }
    return 0;
}
