#include <iostream>
using namespace std;

int main()
{
    //Part A
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if ((i*i)+(j*j)+(k*k)==n)
                {
                    cout<<"("<<i<<","<<j<<","<<k<<")"<<endl;
                }   
            }
        }
    }
    cout<<endl<<endl<<endl;

    //Part B
    int a;
    cout<<"Enter a number: ";
    cin>>a;

    for (int i = 0; i <=a; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            for (int k = 0; k <= a; k++)
            {
                if ((i)+(j)+(k)==a)
                {
                    cout<<i<<"+"<<j<<"+"<<k<<" = "<<a<<endl;
                }
                
            }   
        }   
    }
     
    return 0;
}