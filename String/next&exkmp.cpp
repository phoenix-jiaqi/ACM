// next数组 扩展KMP
 
// t字符串的所有后缀字符串
// 在s串中的公共前缀
 
char s[N],t[N];
ll extend[N],nxt[N];
ll slen,tlen;
void getnxt(char* t)
{
    mem(nxt,0),nxt[0]=tlen;
    ll a=1,p;
    while(a<tlen&&t[a]==t[a-1]) a++;
    nxt[1]=a-1;a=1;
    for(ll i=2;i<tlen;i++){
        p=a+nxt[a]-1;
        if(i-1+nxt[i-a]<p) nxt[i]=nxt[i-a];
        else{
            ll j=(p-i+1)>0?p-i+1:0;
            while(i+j<tlen&&t[i+j]==t[j]) j++;
            nxt[i]=j,a=i;
        }
    }
}
void exkmp(char* s,char* t) //s->extend t->nxt
{
    getnxt(t);
    ll a=0,p=0,len=min(slen,tlen);
    while(p<len&&t[p]==s[p]) p++;
    extend[0]=p;
    for(ll i=1;i<slen;i++){
        p=a+extend[a]-1;
        if(i-1+nxt[i-a]<p) extend[i]=nxt[i-a];
        else{
            ll j=(p-i+1)>0?p-i+1:0;
            while(j<tlen&&i+j<slen&&s[i+j]==t[j]) j++;
            extend[i]=j,a=i;
        }
    }
}
