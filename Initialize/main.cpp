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
const int M=1e5+7,N=1e5+7;
int T,k,m,n;
 
int main()
{
    //scanf("%d",&T);
    while(~scanf("%d",&n))
    {
 
    }
 
    return 0;
}
/*******************************Sample**************************************
 
 
****************************************************************************/
