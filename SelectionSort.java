public class SelectionSort
{
    int input[]={7,4,10,8,3,1};
    
    int min(int index)
    {
        int temp=input[index];
        int minIndex=index;
        for(int i=index+1;i<input.length;i++)
        {
            if(input[i]<temp)
            {
                temp=input[i];
                minIndex=i;
            }
        }
        return minIndex;
    }

    void sort()
    {
        int minIndex,temp;
        for(int j=0;j<input.length;j++)
        {
            minIndex=min(j);
            temp=input[minIndex];
            input[minIndex]=input[j];
            input[j]=temp;
        }
    }
    public static void main(String[] args)
    {
        SelectionSort ss=new SelectionSort();
        ss.sort();

        for(int k=0;k<ss.input.length;k++)
            System.out.print(" "+ss.input[k]);
    }
}
