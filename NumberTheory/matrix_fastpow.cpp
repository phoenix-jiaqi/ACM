
int len;
struct matrix{
    int v[N][N];
    matrix(){
        mem(v,0);for(int i=0;i<len;i++) v[i][i]=1;
    }
    void init(){mem(v,0);}
    void operator=(matrix t){
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                this->v[i][j]=t.v[i][j];
    }
    matrix operator*(matrix t){
        matrix res;
        res.init();
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                for(int k=0;k<len;k++)
                    res.v[i][j]+=this->v[i][k]*t.v[k][j];
        return res;
    }
};
matrix fpow(matrix t,int k)
{
    matrix res;
    while(k){
        if(k&1)
            res=res*t;
        t=t*t;
        k>>=1;
    }
    return res;
}
