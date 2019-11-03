#include <bits/stdc++.h>
using namespace std;typedef long long ll;
template<class orz>inline void read(orz &x){x=0;bool f=0;char ch=getchar();while(ch<'0'||ch>'9') (ch=='-')&&(f=1),ch=getchar();while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();f&&(x=-x);}
template<class orz>inline void out(orz x){if(x<0) putchar('-'),x=-x;if(x>9) out(x/10);putchar(x%10+'0');}
#define inf 0x3f3f3f3f
#define fuck(x) out(x),putchar(10)
#define mem(a,b) memset(a,b,sizeof(a))
///******************************head*************************************///
const double eps=1e-9;//const ll mod=1e9+7;//998244353;//9989783;
const int N=2e6+7;
ll n,cot=0,k,mod,a[100005];
bool vis[2000005];
//  https://ac.nowcoder.com/acm/contest/317/H
void init(ll x) //x为可能出现的最大底数
{
    a[cot++]=2;
    for(ll i=3;i<=x;i+=2){
        if(!vis[i]){
            a[cot++]=i;
            for(int j=i;j<=x;j+=i)
                vis[j]=true;
        }
    }
}
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
ll cal(ll x,ll p)
{
    ll ans=0,t=p;
    while(x>=p)
        ans+=x/p,p*=t;
    return ans;
}
ll c(ll n,ll m)
{
    ll ans=1,num;
    for(int i=0;i<cot;i++){
        num=cal(n,a[i])-cal(m,a[i])-cal(n-m,a[i]);
        ans=ans*qpow(a[i],num)%mod;
    }
    return ans;
}
int main()
{
    read(n),read(k),read(mod);
    init(n<<1);
    fuck((c(n<<1,n)+mod-c(n<<1,n-k))%mod);
}
/*******************************Sample**************************************
10 5 100000007
 
169252
****************************************************************************/
