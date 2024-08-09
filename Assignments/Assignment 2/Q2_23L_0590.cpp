//Program to findconsecutive three multiples of a number

#include <iostream>
using namespace std;

int main()
{
    //Declaring variables and I/O
    int n;
    bool test=false;
    cout<<"Enter a number: ";
    cin>>n;

    //Using loops to find multiples
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j < i+2; j++)
        {
            for (int k = i+2; k < i+3; k++)
            {
                if (i*j*k==n)
                {
                    cout<<"Consecutive numbers are: "<<i<<","<<j<<","<<k<<endl;
                    test=true;
                }
                
            }
            
        }
        
    }
    if(test==false){
        cout<<n<<" contain no three consecutive multiples."<<endl;
    }
    
    return 0;
}