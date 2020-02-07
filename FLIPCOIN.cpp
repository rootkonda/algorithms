#include <iostream>

int main()
{
    int n,q,cmd[3],count;
    int res[100001][100001]={-1};

    scanf("%d %d",&n,&q);

    int a[100001]={};

    while(q-- >0)
    {
        for(int i=0;i<3;i++)
            scanf("%d",&cmd[i]);
        
        if(cmd[0]==0)
        {
            count=0;
            for(int j=cmd[1];j<=cmd[2];j++)
            {  
                 a[j]=(a[j]==0 ? 1 : 0);
                 if(a[j]==1)
                    res[j][cmd[2]]=count++;
            }
        }
        else
        {
            count=0;
            for(int k=cmd[1];k<=cmd[2];k++)
            {
                if(a[k]==1)
                    count++;
            }
            printf("%d\n",count);
            res[cmd[1]][cmd[2]]=count;
        }
    }

    return 0;
}