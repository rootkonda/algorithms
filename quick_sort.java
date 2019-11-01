public class quick_sort{
    
    int partition(int low,int high,int[] input)
    {
        int pivot=input[low];
        int i=low; int j=high;
        int temp;

        while(--j>=++i)
        {
            while(input[i]<=pivot)
                i++;
            
            while(input[j]>pivot)
                j--;
            
            if(i<j)
            {
                temp=input[j];
                input[j]=input[i];
                input[i]=temp;
            }
            else
            {
                break;
            }
        }
        temp=input[j];
        input[j]=input[low];
        input[low]=temp;

        return j;
    }

    void quickSort(int l, int h,int[] input)
    {
        if(l<h)
        {
            int j=partition(l,h,input);

           quickSort(l, j,input);
           quickSort(j+1,h,input);
        }
    }

    public static void main(String[] args)
    {
        final int MAXVAL=100000;
        int input[]={10,16,8,12,15,6,3,9,5,MAXVAL};
        
        quick_sort qs = new quick_sort();
        qs.quickSort(0, input.length-1,input);
        
        for(int k=0;k<input.length-1;k++)
        {
            System.out.print(" "+input[k]);
        }
        
    }
}
