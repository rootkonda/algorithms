#include <iostream>
#include <string.h>

using namespace std;

char set[] = {'a','b','c','d'};
char *temp;

int k = 2;

bool print(int level)
{
    if(level<k)
    {
        for(int i=0;i<strlen(set)-1;i++)
        {
            temp[level]=set[i];
            if(!print(level+1))
            {
                cout << temp;
                cout << "\n";
            }    
        }
        return true;
    }
    else
        return false;
   
}


int main ()
{
    temp = new char[strlen(set)];
    print(0);
    delete []temp;
    return 1;
}
