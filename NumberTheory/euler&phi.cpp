//https://ac.nowcoder.com/acm/contest/317/D
//牛客19年寒假训练赛第一场D题
 
//与x互质的因子的个数
ll phi(ll x)
{
    ll ret=1;
    for(ll i=2;i*i<=x;i++)if(x%i==0){
        x/=i,ret*=i-1;
        while(x%i==0) x/=i,ret*=i;
    }
    if(x>1) ret*=x-1;
    return ret;
}
// 与x互质的因子的和 sum = phi(x)*x/2
// phi(质数)=1
// 欧拉降幂 x^k ==== x^( k % phi(mod) + phi(mod) )
 
 
//线性求n个数的phi值
 
const int N = 1e6+10 ;
int phi[N],prime[N],tot;
void euler()
{
    phi[1] = 1;
    for(int i = 2; i < N; i ++){
        if(!phi[i]){
            phi[i] = i-1;
            prime[tot ++] = i;
        }
        for(int j = 0; j < tot && 1ll*i*prime[j] < N; j ++){
            if(i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j]-1);
            else{
                phi[i * prime[j] ] = phi[i] * prime[j];
                break;
            }
        }
    }
}
