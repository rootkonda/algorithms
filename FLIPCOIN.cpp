#include <iostream>
#include <math.h>

typedef long long ll;

ll st[1000000]={0};
ll lazy[1000000]={0};

inline ll GetMid(ll a, ll b)
{
    return a+(b-a)/2;
}


ll HeadCount(ll ss,ll se,ll qs,ll qe,ll si)
{
    ll mid;
    ll left,right;
    
    if(lazy[si]==1)
    {
        st[si]=(se-ss)+1-st[si];
        if(ss!=se)
        {
            lazy[(2*si)+1]=1-lazy[(2*si)+1];
            lazy[(2*si)+2]=1-lazy[(2*si)+2];
        }
        lazy[si]=0;
    }
    
    if(ss >qe || se <qs)
        return 0;
    
    if(ss>=qs && se<=qe)
    {
        return st[si];
    }
    mid=GetMid(ss, se);
    left=HeadCount(ss, mid, qs, qe, (2*si)+1);
    right=HeadCount(mid+1, se, qs, qe, (2*si)+2);
    
    return left+right;
   
}

ll FlipCoin(ll ss,ll se,ll qs,ll qe,ll si)
{
    ll mid;
    
    if(lazy[si]==1)
    {
        st[si]=(se-ss)+1-st[si];
        if(ss!=se)
        {
            lazy[(2*si)+1]=1-lazy[(2*si)+1];
            lazy[(2*si)+2]=1-lazy[(2*si)+2];
        }
        lazy[si]=0;
    }
    
    if(ss >qe || se <qs)
        return st[si];
        
    if(ss>=qs && se<=qe)
    {
        st[si]=((se-ss)+1)-st[si];
        if(se!=ss)
        {
            lazy[(2*si)+1]=1-lazy[(2*si)+1];
            lazy[(2*si)+2]=1-lazy[(2*si)+2];
        }
        
        return st[si] ;
    }
    
    
    mid=GetMid(ss, se);
    ll left=FlipCoin(ss, mid, qs, qe, (2*si)+1);
    ll right=FlipCoin(mid+1, se, qs, qe, (2*si)+2);
    
    st[si]=left+right;
    return st[si];
    
}
    


int main(int argc, const char * argv[]) {

    int t,n,cmd[3];
    
    scanf("%d %d",&n,&t);
    
    while(t-- > 0)
    {
        for(int i=0;i<3;i++)
            scanf("%d",&cmd[i]);

        if(cmd[0]==0)
        {
            FlipCoin(0, n-1, cmd[1], cmd[2], 0);
        }
        else
        {
            printf("%llu \n",HeadCount(0, n-1, cmd[1], cmd[2], 0));
        }

    }
    
    return 0;
}
