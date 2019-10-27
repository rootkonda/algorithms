// Dynamic Programming Approach

public class subset_sum
{
    public void backTracing(int i, int j, boolean[][] output,int[] mainSet)
    {
        if(output[i][j] && i-1>-1 && j>-1)
        {
            if(output[i-1][j])
            {
                backTracing(i-1, j, output, mainSet);
            }
            
            else if(output[i-1][j-mainSet[i]])
            {
                System.out.print(" "+mainSet[i]);
                backTracing(i-1, j-mainSet[i], output,mainSet);
            }
            
        }
    }

    public void subsum(int[] mainSet,int sum, boolean[][] output)
    {
        for(int i=0;i<mainSet.length;i++)
        {
            for(int j=0;j<sum;j++)
            {
                if(j==0)
                    output[i][j]=true;
                else
                    output[i][j]=false;
            }    
        }

        for(int i=1;i<mainSet.length;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(mainSet[i]>j)
                {
                    output[i][j] = output[i-1][j];
                }
                else
                {
                    output[i][j] = output[i-1][j-mainSet[i]] || output[i-1][j]; 
                }
            }
        }
        System.out.println("Subset sum available ?: "+output[mainSet.length-1][sum]);
    }

    public static void main(String[] args)
    {
        int mainSet[] ={0,2,3,7,8,10};
        boolean output[][]=new boolean[7][13];
        int sum=12;

        subset_sum ss = new subset_sum();
        ss.subsum(mainSet, sum, output);
        System.out.println("Combination: ");
        ss.backTracing(mainSet.length-1,sum,output,mainSet);
    }
    

}
