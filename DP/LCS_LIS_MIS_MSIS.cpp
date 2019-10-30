char stra[maxn],strb[maxn];
int lena,lenb,dp[maxn][maxn];
int LCS()
{
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
            if(stra[i-1]==strb[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return dp[lena][lenb];
}
 
/// LIS 最长递增子序列
int a[maxn],c[maxn],cnt,pos;
int LIS()
{
    c[0]=a[1],cnt=1;
    for(int i=2;i<=n;i++)
        if(a[i]>c[cnt-1])
            c[cnt++]=a[i];
        else{
            pos=lower_bound(c,c+cnt,a[i])-c;
            c[pos]=a[i];
        }
    return cnt;
}
 
/// MIS 最大子段和
int a[maxn],st,en,t,sum,msum;
void MIS()
{
    st=en=t=1,sum=0,msum=-INF;
    for(int i=1;i<=n;i++){
        if(sum<0) t=i,sum=a[i];
        else sum+=a[i];
        if(sum>msum) en=i,st=t,msum=sum;
    }
}
 
/// MSIS 递增子序列最大和
int a[maxn],c[maxn];
int MSIS()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        c[i]=a[i];
    for(int i=2;i<=n;i++)
    for(int j=1;j<i;j++)
    if(a[i]>a[j]&&c[i]<c[j]+a[i])
        c[i]=c[j]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(ans,c[i]);
    return ans;
}
