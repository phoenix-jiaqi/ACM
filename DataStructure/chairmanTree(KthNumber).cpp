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
