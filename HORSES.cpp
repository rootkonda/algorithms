#include <iostream>
#include <algorithm>
#define VAL_MAX 1000000007
const int N_MAX=5000;
const int T_MAX=10;


int main()
{
    int T,N,temp;
    std::cin >> T;
    long long arr[50001];
    
    while(T-- > 0)
    {
        std::cin >> N;
        
        for (int i=0;i<N;i++)
            std::cin>>arr[i];
        
        std::sort(arr,arr+N);
        temp=VAL_MAX;
        for(int i=0;i<N-1;i++)
        {
            if(abs(arr[i]-arr[i+1])<temp)
                temp=abs(arr[i]-arr[i+1]);
        }
        std::cout<<temp<<std::endl;
    }
    
    return 0;

}
