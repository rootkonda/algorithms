public class BubbleSort
{
    int input[]={15,16,6,8,5};

    void sort()
    {
        int temp;
        for(int i=0;i<input.length-1;i++)
        {
            for(int j=0;j<input.length-1;j++)
            {
                if(input[j]>input[j+1])
                {
                    temp=input[j+1];
                    input[j+1]=input[j];
                    input[j]=temp;
                }
            }
        }
    }
    public static void main(String[] args)
    {
        BubbleSort bs=new BubbleSort();
        bs.sort();

        for(int k=0;k<bs.input.length;k++)
             System.out.print(" "+bs.input[k]);
    }
}
