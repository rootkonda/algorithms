public class MergeSort
{
    int input[]={3,-1,6,4,2,0,10};
    int low, high, mid;

    void merge(int l,int h)
    {
        int mid=(l+h)/2;
        int i=l,r=0,j=mid+1;
        int temp[]=new int[h-l+1];

        while(i<=mid && j<=h)
        {
            if(input[i]<=input[j])
            {
                temp[r++]=input[i++];
            }
            else
            {
                temp[r++]=input[j++];
            }
        }
        while(i<=mid)
            temp[r++]=input[i++];

        while(j<=h)
            temp[r++]=input[j++];

        i=l;
        for(int k=0;k<temp.length;k++)
            input[i++]=temp[k];

    }

    void sort(int l,int h)
    {
        mid=(l+h)/2;
        
        if(l<h)
        {
            
            sort(l,mid);
            sort(mid+1,h);
            merge(l,h);
        }
    }
    public static void main(String[] args)
    {
        MergeSort ms = new MergeSort();
        ms.low=0;
        ms.high=ms.input.length-1;
        ms.sort(ms.low,ms.high);

        for(int k=0;k<ms.input.length;k++)
          System.out.print(" "+ms.input[k]);
    }
}
