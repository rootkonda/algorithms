1. MissingInteger
Find the smallest positive integer that does not occur in a given sequence.
This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int ans=10000005;
    bool isOne=false;
    
    if(A.size()==1)
    {
        if(A[0]==1)
          return 2;
        else
          return 1;
    }
    if(A[0]==1)
      isOne = true;
    for(int i=1;i<(int)A.size();i++)
    {
        if(A[i]==1)
          isOne=true;
        if(A[i]>1)
        {
            int diff = A[i]-A[i-1];
            if(diff>1)
            {
                int value = A[i-1]+1;
                for(int j=1;j<diff-1;j++)
                {
                    if(value>0)
                    {
                         ans = min(ans,value);
                         break;
                    }
                }
                if(value>0)
                    ans = min(ans,value);
            }
        }
    }
    if(ans==10000005)
    {
        if(!isOne)// we have to put this condition outside.
          return 1;
        else
          return A[A.size()-1]+1;
    }
    return ans;
    
}
