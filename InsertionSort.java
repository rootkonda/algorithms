public class InsertionSort
{
    int input[]={5,-1,4,10,1,6,2};

    void sort()
    {
        int temp,i,j;
        for(j=1;j<input.length;j++)
        {
            temp=input[j];
            for(i=j-1;i>=0;i--)
            {
                if(input[i]>temp)
                {
                    input[i+1]=input[i];
                }
                else
                    break;
            }
            input[i+1]=temp;
        }

    }

    public static void main(String[] args)
    {
        InsertionSort is=new InsertionSort();
        is.sort();

        for(int k=0;k<is.input.length;k++)
            System.out.print(" "+is.input[k]);
    }
}
