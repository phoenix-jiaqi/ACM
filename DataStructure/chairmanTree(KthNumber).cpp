//POJ 2104   HDOJ 2665
const int M=32,N=1e5+7;
 
ll n,m;
int cnt,root[N],a[N],x,y;
struct node{int l,r,sum;}T[N*25];
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(mid>=pos)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(sum>=k)return query(l,mid,T[x].l,T[y].l,k);
    else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
 
int main()
{
    read(n);
    //v.clear(),cnt=0,mem(T,0);//init
    for(int i=1;i<=n;i++)
        read(a[i]),v.push_back(a[i]);
    sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) update(1,n,root[i],root[i-1],getid(a[i]));
    int x,y,k;
    read(m);
    while(m--){
        read(x),read(y),read(k);//升序第k个数
        k=y-x-k+2;//降序第k个数
        fuck(v[query(1,n,root[x-1],root[y],k)-1]);
    }
   
    return 0;
}
/*******************************Sample**************************************
5
1 2 3 4 5
2
1 5 2
2 3 2
 
4
2
****************************************************************************/


//x<k where index x between l and r
#include<bits/stdc++.h>
using namespace std;
#define MAXM 2000005
#define MAXN 100005
int n,q,m,s[MAXM],lc[MAXM],rc[MAXM],root[MAXN],a[MAXN],i,j,k;
void fix(int &R,int &R1,int l,int r,int x)
{
    R=++m;
    s[R]=s[R1]+1;
    if(l==r)return;
    int mid=l+r>>1;
    if(x<=mid){
        fix(lc[R],lc[R1],l,mid,x);
        rc[R]=rc[R1];
    }else{
        fix(rc[R],rc[R1],mid+1,r,x);
        lc[R]=lc[R1];
    }
}
int ask(int R,int l,int r,int x)
{
    if(!R)return 0;
    if(l==r)return s[R];
    int mid=l+r>>1;
    if(x<=mid)return ask(lc[R],l,mid,x);
    return s[lc[R]]+ask(rc[R],mid+1,r,x);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
        fix(root[i],root[i-1],1,100000,a[i]);
    }
    while(q--){
        scanf("%d%d%d",&i,&j,&k);
        printf("%d\n",ask(root[j],1,100000,k)-ask(root[i-1],1,100000,k));
    }
    return 0;
}
