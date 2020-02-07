#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

const int MAX = 100005;

int n,q;
int Old2NewIndexRel[MAX],New2OldIndexRel[MAX];

pair<ll,int> input[MAX];
int cmd;
ll val;
ll st[MAX<<2];
ll lazy[MAX<<2]={0};

void BuildSegTree(int left,int right,int pos)
{
    if(left==right)
    {
        st[pos]=input[left].first;
        return;
    }

    int mid=(left+right)/2;
    
    BuildSegTree(left, mid, (2*pos));
    BuildSegTree(mid+1, right, (2*pos)+1);
    
    st[pos]=max(st[(2*pos)],st[(2*pos)+1]);
    
}

void LazyCheck(int pos,int left, int right)
{
    if(lazy[pos])
    {
        st[pos]+=lazy[pos];
        if(left!=right)
        {
            lazy[2*pos]+=lazy[pos];
            lazy[2*pos+1]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    return;
}

void Add(int pos,int left,int right,int val,int l,int r)
{
    LazyCheck(pos, left, right);
    
    if(left>r || right<l)
        return;
    if(left>=l && right<=r)
    {
        lazy[pos]+=val;
        LazyCheck(pos, left, right);
        return;
    }
    int mid=(left+right)/2;
    Add(2*pos,left,mid,val,l,r);
    Add(2*pos+1,mid+1,right,val,l,r);
    
    st[pos]=max(st[2*pos],st[2*pos+1]);
}

ll GetValue(int pos, int left, int right, int index)
{
    LazyCheck(pos, left, right);
    if(left==right)
        return st[pos];
    
    int mid=(left+right)/2;
    if(index<=mid)
        return GetValue(2*pos,left,mid,index);
    else
        return GetValue(2*pos+1, mid+1, right, index);
    
}

int NextHighestElement(int pos, int left, int right, ll val)
{
    LazyCheck(pos, left, right);
    if(st[pos]<val)
        return right+1;
    if(left==right)
        return left;
    
    int mid=(left+right)/2;
    LazyCheck(2*pos, left, mid);
    LazyCheck(2*pos+1, mid+1, right);
    
    if(st[2*pos]>=val)
        return NextHighestElement(2*pos, left, mid, val);
    else
        return NextHighestElement(2*pos+1, mid+1, right, val);
        
}


int main()
{
    scanf("%d %d",&n,&q);
    
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&input[i].first);
        input[i].second=i;
    }
    sort(input+1,input+n+1);
    for(int j=1;j<=n;j++)
    {
        Old2NewIndexRel[input[j].second]=j;
        New2OldIndexRel[j]=input[j].second;
    }
    
    BuildSegTree(1, n, 1);
    
//    for(int i=1;i<=15;i++)
//    {
//        printf("%lld\n",st[i]);
//    }
    
    while(q--)
    {
        scanf("%d %lld",&cmd,&val);
        
        if(cmd==1)
        {
            ll LastIndex=val;
            int LastPosition=Old2NewIndexRel[val];
            ll LastValue=GetValue(1, 1, n, LastPosition);
            int CurrPosition=NextHighestElement(1, 1, n, LastValue+1)-1;
            int CurrIndex=New2OldIndexRel[CurrPosition];
            
            if(LastIndex==CurrIndex)
            {
                Add(1, 1, n, 1, LastPosition,LastPosition);
            }
            else
            {
                swap(Old2NewIndexRel[LastIndex],Old2NewIndexRel[CurrIndex]);
                swap(New2OldIndexRel[LastPosition],New2OldIndexRel[CurrPosition]);
                Add(1, 1, n, 1, CurrPosition, CurrPosition);
            }
        }
        else if(cmd==2)
        {
            printf("%d\n",n-NextHighestElement(1, 1, n, val)+1);
        }
        else if(cmd==3)
        {
            int x=NextHighestElement(1, 1, n, val);
            if(x!=n+1)
                Add(1, 1, n, -1, x, n);
        }
    }
    return 0;
}
