#include <iostream>
using namespace std;
int n;
int main()
{
    //Vatiables, I/O and checking for invalid
    do
    {
        bool test=false;
        do
        {
            cout<<"Enter a number to know if it is a perfect square: ";
            cin>>n;
            if (n<0 && n!=-1)
            {
                cout<<"Enter a positive integer!"<<endl;
            }
            else if (n==-1)
            {
                return 0;
            }
            
            
        } while (n<0 && n!=-1);
        
        

        //Checking for perfect square
        for (int i = 0; i <= n; i++)
        {
            if (i*i==n)
            {
                cout<<n<<" is a perfect square and its square root is: "<<i<<endl;
                test=true;
                break;
            }
            
        }
        if (test==false)
        {
            cout<<n<<" is not a perfect square."<<endl;
        }

    }while (n!=-1);
    return 0;
}