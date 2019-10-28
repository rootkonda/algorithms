public class LongIncrSeq
{
    public static void main(String[] args)
    {
        int inputArr[]={3,4,-1,0,6,2,3};
        int outputArr[]=new int[inputArr.length];
        int longIncrSeq=0;

        for(int i=0;i<inputArr.length;i++)
        {
            outputArr[i]=1;
        }

        for(int i=1;i<inputArr.length;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(inputArr[j]<inputArr[i])
                {
                    if(outputArr[j]+1 > outputArr[i])
                        outputArr[i]=outputArr[j]+1;
                }

            }
        }
        for(int i=0;(i+1)<inputArr.length;i++)
        {
             if(outputArr[i]>outputArr[i+1])
                longIncrSeq = outputArr[i];
             else
                longIncrSeq = outputArr[i+1];
        }
        System.out.println(longIncrSeq);
    }
}
