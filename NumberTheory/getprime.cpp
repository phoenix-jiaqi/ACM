bool isprime[N];
int prime[N],pnum=0;
void getprime()
{
    mem(isprime,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i])
            prime[++pnum]=i;
        for(int j=1;j<=pnum&&i*prime[j]<N;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
