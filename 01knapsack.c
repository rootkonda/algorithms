/* 

Name: 0/1 Knapsack algorithm
Author: rootkonda
References:
https://www.youtube.com/watch?v=8LusJS5-AGo&t=800s
https://www.youtube.com/watch?v=nLmhmB6NzcM&t=1040s
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

*/
    
#include <stdio.h>
#include <stdlib.h>

static inline int max ( int a, int b ) { return a > b ? a : b; }

int main()
{
    int capacity=0;
    int *wgt, nItems, *value;
    printf("\nEnter total weight:\t");
    scanf("%i",&capacity);
    printf("\nEnter no of items:\t");
    
    scanf("%i",&nItems);

    /*
      We are considering the scenario where item weight is zero and total weight is also zero.
      Hence incrementing no of items and total weight by 1 while allocating memory
    */

    int output[nItems+1][capacity+1];
    
    //Captures the weights of individual items
    wgt=calloc(nItems, sizeof(int));
    for(int i=0; i<nItems;i++)
    {
        printf("\nEnter weight of item %i:\t",i+1);
        scanf("%i",(wgt+i));
    }

    //Captures the values of individual item weights
    value=calloc(nItems, sizeof(int));
    for(int i=0; i<nItems;i++)
    {
        printf("\nEnter value of item %i:\t",i+1);
        scanf("%i",(value+i));
    }   

    
    for(int i=0; i<=nItems; i++)
    {
        for(int j=0; j<=capacity; j++)
        {
            if((i==0 && (j < *(wgt+i))) || j==0) // For first item and item weight is greater than total weight or first total weight.
            {
                output[i][j] = 0;
                continue;
            }
            else if(i==0) // For first item and all other total weights apart from first.
            {
                output[i][j] = value[i];
                continue;
            }
            if( j < *(wgt+i)) // For all other items, check total weight is less than item weight 
            {
               output[i][j] = output[i-1][j];
            }  
            else
            {
                output[i][j] = max((value[i]+output[i-1][j-(*(wgt+i))]),output[i-1][j]); // Find the maximum between choices 1(when we select the item) and 0(when we skip the item)
            }
        }
        
    }
    //Last element in the output array is the answer
    printf("\nMaximum value we can get for given data is: %i",output[nItems][capacity]); 
    //free the memory allocated by calloc function
    free(wgt);
    free(value);
    printf("\n");
    
}
