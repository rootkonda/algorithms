/***
Name: Longest Common Subsequence(lcs) algorithm
Author: rootkonda
References:
https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=2
https://www.youtube.com/watch?v=sSno9rV8Rhg
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
***/

#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) { return (a>b) ? a: b;};
char seq1[] = {'\0','l','o','n','g','e','s','t'};
char seq2[] = {'\0','s','t','o','n','e'};

// Backtrace the output and find the corresponding characters
void subsequence(int row, int col, int lcs[][sizeof(seq1)])
{
    //stop recursion when it reaches zero
    if(row==0 || col==0)
            return;
   
    //check whether characters at left and top of current character is not same
    if((lcs[row][col] != lcs[row][col-1]) && (lcs[row][col] != lcs[row-1][col]))
    {
        printf("%c\n",seq1[col]);
        subsequence(row-1,col-1,lcs); // recurse again from diagonal element(row-1,col-1)
    }
    else
    {
        if(row==0 || col==0 )
            return;
        if(lcs[row][col]==lcs[row][col-1]) // Character to the left is same ?
            subsequence(row,col-1,lcs);
        else if(lcs[row][col]==lcs[row-1][col]) // Character to the top is same ?
            subsequence(row-1,col,lcs);
    }
    return;
}

int main()
{
    int lcs[sizeof(seq2)][sizeof(seq1)]={0};
    int i,j;

    for(i=0; i<sizeof(seq2);i++)
    {
        for(j=0;j<sizeof(seq1);j++)
        {
            if(seq2[i]=='\0' || seq1[j]=='\0') // added \0 to the output array to support the logic when we use i-1 or j-1 at the beginning
            {
                continue;
            }
            if(seq2[i] == seq1[j]) // if characters are same, then increment the diagonal character value by 1
            {
                lcs[i][j] = 1+lcs[i-1][j-1]; 
            }
            else // maximum of characters to left and top of the character
            {
                lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
            }   
        }
    }
    printf("\n");
    subsequence(i,j,lcs);
}
