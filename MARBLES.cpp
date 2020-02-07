/* Referecens
Formula:(n-1)C(n-k);
            https://wrytin.com/ricksmith/marbles-codechef-solution-jluc5x0v
            https://medium.com/i-math/combinations-permutations-fa7ac680f0ac
            combinations with repetitions (N+R-1)CR
*/
#include <iostream>

using namespace std;

long long factorial(long long n, long long r)
{
    long long res=1;
    
    if(n-r < r)
        r = n-r;
    
    for(long long i=1;i<=r;i++)
    {
        res*=n;
        res/=i;
        n--;
    }
    return res;
}

int main ()
{
    int nTestCases;
    long long nMarbles, kColors;

    cin >> nTestCases;
    
    while(nTestCases-- )
    {
        cin >> nMarbles;
        cin >> kColors;
        
    
        long long  n=(nMarbles-1);
        long long  r=(nMarbles-kColors); // to select atleast 1 marble of different K-type each so the remaining marbles are n-k

        cout << factorial(n,r);
        cout << "\n"; // nCr formula
    }
    return 0;
    
}