// tarjan  强连通 缩点
// https://nanti.jisuanke.com/t/A1252 最少连多少条边 使整个图强连通
 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
namespace fast{inline char nc(){static char buf[100000],*L=buf,*R=buf;return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;}template<class orz> inline void qread(orz &x){x=0;char ch=nc();bool f=0;while(ch<'0'||ch>'9')(ch=='-')&&(f=1),ch=nc();while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=nc();f&&(x=-x);}}using namespace fast;
template<class orz>inline void read(orz &x){x=0;bool f=0;char ch=getchar();while(ch<'0'||ch>'9')(ch=='-')&&(f=1),ch=getchar();while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();f&&(x=-x);}
template<class orz>inline void out(orz x){(x<0)&&(putchar('-'),x=-x);if(x>9)out(x/10);putchar(x%10+'0');}
#define inf 0x3f3f3f3f
#define fuck(x) out(x),putchar(10)
#define space(x) out(x),putchar(32)
#define mem(a,b) memset(a,b,sizeof(a))
///******************************head*************************************///
const double eps=1e-9;const ll mod=1e9+7;//998244353;
const int M=1e5+7,N=1e4+7;int T;
 
int n,m,num;
int dfn[N],low[N],belong[N],cnt,st[N],lst;
int ot[N],in[N];
bool vis[N];
int head[N],nxt[M],to[M],tot;
inline void init()
{
    num=cnt=lst=tot=0;
    mem(head,-1);
    mem(dfn,0);mem(low,0);
    mem(vis,false),mem(in,0),mem(ot,0);
}
inline void addedge(int u,int v)
{
    to[tot]=v,nxt[tot]=head[u],head[u]=tot++;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++cnt;vis[u]=true;
    st[lst++]=u;
    for(int i=head[u],v;~i;i=nxt[i]){
        v=to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        num++;
        int x;
        do{
            x=st[--lst];
            vis[x]=false,belong[x]=num;
        }while(x!=u);
    }
}
 
int main()
{
    read(T);while(T--){
        read(n),read(m);
        init();
        for(int i=0,u,v;i<m;i++){
            read(u),read(v);
            addedge(u,v);
        }
        for(int i=1;i<=n;i++)if(!dfn[i]) tarjan(i);
        for(int i=1;i<=n;i++){
            for(int j=head[i],v;~j;j=nxt[j]){
                v=to[j];
                if(belong[i]!=belong[v]) ot[belong[i]]++,in[belong[v]]++;
            }
        }
        int ans,ans1=0,ans2=0;
        for(int i=1;i<=num;i++){
            if(!in[i]) ans1++;
            if(!ot[i]) ans2++;
        }
        ans=max(ans1,ans2);
        if(num==1) fuck(0);
        else fuck(ans);
    }
 
    return 0;
}
/*******************************Sample**************************************
2
4 3
1 2
2 3
3 4
4 4
1 2
1 4
3 2
3 4
 
****************************************************************************/
