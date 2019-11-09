#include <iostream>
#include <string.h>

using namespace std;

int visited[5][5];

void check(string input,int low, int high)
{
    int i=low,j=high;
    bool isPalindrome=true;

    visited[low][high]++; 
    if(i<=j)
    {
       check(input,i,high-1);
       check(input,i+1,high);
      

        while(i<=j)
        {
            if(input[i++]!=input[j--])
            {
                isPalindrome=false;
                break;
            }  
        }

        if(isPalindrome && visited[low][high]==1)
        {
            for(int k=low;k<=high;k++)
            {
                cout << input[k];
            }
            cout << " ";   
            cout << "\n";   
        } 
    }
    
}

int main()
{
    string arr="geeks";    

   /* 
    m, a, d, a, m
    ma, ad, da, am
    mad ada dam
    mada adam
    madam 
    */

    check(arr,0,arr.size()-1);
}
