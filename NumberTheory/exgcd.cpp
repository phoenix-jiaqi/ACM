int x,y;
ll gcd(int a,int b){return b==0?a:gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x=1,y=0;return a;
    }
    ll res=exgcd(b,a%b,x,y);
    ll temp=x;
    x=y,y=temp-a/b*y;
    return res;
}
ll cal(ll a,ll b,ll c)  //ax+by=c
{
    ll x,y,g=exgcd(a,b,x,y);
    if(c%g!=0) return -1;
    x*=c/g,b/=g,b=b<0?-b:b;
    return x%b<=0?x%b+b:x%b;
}
//int a,b;
//a=8,b=-36;
//printf("%d\n",cal(a,b,4));
