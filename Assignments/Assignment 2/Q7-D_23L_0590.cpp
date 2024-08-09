#include <iostream>
using namespace std;

int main()
{
    int a=0,b=1,sum=0,evenSum=0;
    for (int i = 0; sum <4000000; i++)
    {       
        sum=a+b;
        a=b;
        b=sum;

        if (sum%2==0)
        {
            evenSum+=sum;
        }
        else{
            continue;
        }
        
    }
    cout<<evenSum<<endl;
    
    return 0;
}