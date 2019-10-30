void zero(int w,int v)
{
    for(int i=m;i>=w;i--)
        dp[i]=max(dp[i],dp[i-w]+v);
}
void com(int w,int v)
{
    for(int i=w;i<=m;i++)
        dp[i]=max(dp[i],dp[i-w]+v);
}
void mul(int w,int v,int cnt)
{
    if(m<=w*cnt) com(w,v);
    else{
        for(int i=1;i<=cnt;cnt-=i,i<<=1) zero(w*i,v*i);
        if(cnt) zero(w*cnt, v*cnt);
    }
}
