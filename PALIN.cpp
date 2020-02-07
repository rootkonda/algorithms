#include<iostream>
#include <cstring>
 
char *n = NULL;
size_t count = 0;
 
int GetValueAt(int index)
{
    return (n[index] - '0');
}
 
void AddNumToStr( int index, int digit )
{
    bool carry = false;
    n[index] += digit;
    
    if( n[index] > '9' )
    {
        carry = true;
        n[index] -= 10;
    }
    
    for( int i = index - 1; i >= 0 && carry; --i )
    {
        if( n[i] == '9' )
        {
            n[i] = '0';
            carry = true;
        }
        else if( n[i] == '\0' )
        {
            n[i] = '1';
        }
        else
        {
            n[i] += 1;
            break;
        }
    }

}
 
void nextPalin( int start, int end )
{
    AddNumToStr( end, 1 );
    
    int i = n[0] ? 0 : start;
    int j = end;
    
    while(i < j - 1)
    {
        int leftDigit = GetValueAt( i );
        int rightDigit = GetValueAt( j );
        if( leftDigit != rightDigit )
        {
            if( leftDigit > rightDigit )
            {
                n[j] = n[i];
                ++i;
                --j;
            }
            else
            {
                AddNumToStr( j, (10 - (rightDigit - leftDigit)) );
            }
        }
        else
        {
            ++i;
            --j;
        }
    }
    
    int leftDigit = GetValueAt( i );
    int rightDigit = GetValueAt( j );
    if( leftDigit > rightDigit )
    {
        n[j] = n[i];
    }
    else if( rightDigit > leftDigit )
    {
        n[i] = n[j] = n[i] + 1;
    }
}
 
int main(int argc, const char * argv[])
{
    int t = 0;
    scanf( "%d\n", &t );
    n = new char[1000002];
    
    while(t-- > 0)
    {
        n[0] = '\0';
        fgets( n + 1, 1000001, stdin );
        count = strlen( n + 1 );
        n[count--] = '\0';
        nextPalin( 1, static_cast<int>(count) );
       
        if(n[0])
            printf("%s\n", n);
        else
            printf("%s\n", n + 1);
    }
    
    delete[] n;
    return 0;
}
