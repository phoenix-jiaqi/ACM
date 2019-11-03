ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
ll fast_pow(ll a,ll k)
{
    ll res=1;
    while(k){
        if(k&1) res=res*a;
        k>>=1;
        a=a*a;
    }
    return res;
}
