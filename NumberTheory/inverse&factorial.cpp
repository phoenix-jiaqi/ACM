ll fac[N],inv[N];
void init()
{
    fac[0]=inv[0]=inv[1]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*ll(i)%mod;
    for(int i=2;i<N;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=2;i<N;i++) inv[i]=inv[i-1]*inv[i]%mod;
}
