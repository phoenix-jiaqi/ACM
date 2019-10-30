///无负数
 
inline char nc(){static char *p1,*p2,buf[100000];return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
template<typename orz>void qrd(orz &x){x=0;char c=nc();while(!isdigit(c))c=nc();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=nc();}
template<typename orz>inline void read(orz &x){x=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();}
template<typename orz>inline void out(orz x){if(x>9)out(x/10);putchar(x%10+'0');}
 
 
 
///有负数
 
inline char nc(){static char *p1,*p2,buf[100000];return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
template<typename orz>void qrd(orz &x){x=0;char c=nc();bool f=0;while(!isdigit(c))(c=='-')&&(f=1),c=nc();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=nc();f&&(x=-x);}
template<typename orz>inline void read(orz &x){x=0;bool f=0;char c=getchar();while(!isdigit(c))(c=='-')&&(f=1),c=getchar();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();f&&(x=-x);}
template<typename orz>inline void out(orz x){if(x<0)putchar('-'),x=-x;if(x>9)out(x/10);putchar(x%10+'0');}
 
 
///fast 快读
namespace fast{static const int BUF=1000000;bool IOerror=false;inline char nc(){static char buf[BUF],*p1=buf+BUF,*pend=buf+BUF;if(p1==pend){p1=buf,pend=buf+fread(buf,1,BUF,stdin);if(pend==p1){IOerror=1;return -1;}}return *p1++;}inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}template<class orz> inline void qread(orz &x){char ch;bool f=false;while(blank(ch=nc()));if(IOerror) return;if (ch=='-') f=true,ch=nc();for(x=ch-'0';(ch=nc())>='0'&&ch<='9';x=(x<<3)+(x<<1)+ch-'0');if(f) x=-x;}}using namespace fast;
 
 
namespace fast{inline char nc(){static char buf[100000],*L=buf,*R=buf;return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;}template<class orz> inline void qread(orz &x){x=0;char ch=nc();bool f=0;while(ch<'0'||ch>'9')(ch=='-')&&(f=1),ch=nc();while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=nc();f&&(x=-x);}}using namespace fast;
template<class orz>inline void read(orz &x){x=0;bool f=0;char ch=getchar();while(ch<'0'||ch>'9')(ch=='-')&&(f=1),ch=getchar();while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();f&&(x=-x);}
template<class orz>inline void out(orz x){(x<0)&&(putchar('-'),x=-x);if(x>9)out(x/10);putchar(x%10+'0');}
 
 
//qread(x)
