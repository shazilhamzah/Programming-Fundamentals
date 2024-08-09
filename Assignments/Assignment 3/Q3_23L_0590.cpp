/*You have an array of zeros and ones, move all zeros to the left and ones to the right.*/

#include <iostream>
using namespace std;

int main()
{
    int n,zeroCount=0,oneCount=0;
    const int abc = 100;
    cout<<"Enter 0's and 1's (-1 to exit):"<<endl;
    do
    {
        
        // CHECKING VALID CONDITIONS AND -1
        cout<<"Enter number: "; cin>>n;
        if (n==-1)
        {
            break;
        }
        else if (n!=0 && n!=1)
        {
            cout<<"Enter valid binary!"<<endl;
        }

        // COUNTING ZEROS AND ONES
        if (n==0)
        {
            zeroCount+=1;
        }
        else if (n==1)
        {
            oneCount+=1;
        }
        
        
        
        
    } while (n==0 || n==1 || n==-1);

    // DEFINING VARIABLE AND ARRAY
    int size=zeroCount+oneCount;
    int arr[abc];
    
    
    // ENTERING VARIABLES
    for (int i = 0; i < zeroCount; i++)
    {
        arr[i]=0;
    }
    for (int i = zeroCount; i < size; i++)
    {
        arr[i]=1;
    }
    
    

    // PRINTING ARRAY
    cout<<"Segregated array is: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}
