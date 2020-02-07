#include <iostream>
#include <algorithm>

long long temp;

int main()
{
    int t,n,k;

    std::cin>>t;

    while(t-- > 0)
    {
        std::cin >> n;
        long long a[n];

        for(int i=0;i<n;i++)
            std::cin >> a[i];
    
        std::cin>>k;
        
        if(k<=n && k>=1)
            temp=a[k-1];

        std::sort(a,a+n);

        for(int j=0;j<n;j++)
            if(a[j]==temp)
                printf("%d\n",j+1);

    }
    return 0;
}