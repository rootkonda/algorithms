#include <iostream>
#include <string.h>

using namespace std;



bool isPalUtil(int num, int* dupNum)
{
    if(num>=0 && num<10)
    {
        return (num==(*dupNum)%10);
    }

    if(!isPalUtil(num/10,dupNum))
        return false;
    
    *dupNum/=10;

    return (num%10==(*dupNum)%10);
}

int isPal(int num) 
{ 
    if (num < 0) 
      num = -num; 
  
    int *dupNum = new int(num);
  
    return isPalUtil(num, dupNum); 
} 


int main ()
{
    int input=-12321;
    isPal(input)? printf("Yes"): printf("No");  

}
