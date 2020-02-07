#include <iostream>

using namespace std;
long long int val[1000000000]={0};

long long int cal(long long int n)
{
    if(n<=1000000000 && n>=0)
    {
        if(val[n]!=0)
            return val[n];
        
        long long int sum = (n/2)+(n/3)+(n/4);

        if(sum>n)
        {
            val[n]=cal(n/2)+cal(n/3)+cal(n/4);
            return val[n];
        }
        else
            val[n]=n;        
    }
    return n;
}

int main()
{
    long long int value,maxAmount;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> value)
    {
        maxAmount=cal(value);
        cout << maxAmount << "\n";        
    }

return 0;

}


