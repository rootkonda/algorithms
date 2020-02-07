#include <iostream>

const int MAX=10000;
int main()
{
    int a,b,res,t;
    std::cin >> a >> b;

    if (a<=MAX && b<a && b>=1)
    {
        res = (a-b)%10!=9 ? (a-b)+1 : (a-b)-1; 

        std::cout << res << std::endl ;
    }   
    
    return 0;
}