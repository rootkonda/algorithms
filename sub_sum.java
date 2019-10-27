import java.util.ArrayList;

public class sub_sum
{
    public static void main(String[] args)
    {
        int set[] = {-5,40,-35,25,1,20};
        int sumValue=0,subset_sum=set[0];
        int subset_size=1,next_set_index=0,counter;
        ArrayList<Integer> output = new ArrayList<Integer>();

        for(;subset_size<set.length && subset_sum!=sumValue;)
        {
            for(int i=0; i<set.length && subset_sum!=sumValue;i++)
            {
                for(int j=i+1;(j<set.length && subset_sum!=sumValue);j++)
                {
                    counter=1;
                    subset_sum=set[i];
                    output.removeAll(output);
                    output.add(set[i]);
                    next_set_index=j;

                    while(next_set_index<set.length && subset_size>counter)
                    {
                            subset_sum+=set[next_set_index];
                            output.add(set[next_set_index]);   
                            counter++;
                            next_set_index++;
                    }
                }
                         
            }
            subset_size++; 
        }
        if(subset_sum==sumValue)
            System.out.println("Subset: "+output);   
    }
}

