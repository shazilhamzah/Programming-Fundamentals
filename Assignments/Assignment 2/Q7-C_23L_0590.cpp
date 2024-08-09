#include <iostream>
using namespace std;

int main()
{
    int a,b,x=0,y=1,sum=0;
    do
    {
        cout<<"Enter starting value: ";
        cin>>a;
        

        cout<<"Enter ending value: ";
        cin>>b;
        

        if (a<=0 || b<=0)
        {
            cout<<"Enter a valid starting or ending value (Range: All natural numbers)!"<<endl;
        }
        
    } while (a<=0 || b<=0);

    for (int i = 1; true ; i++)
    {
        sum=x+y;
        x=y;
        y=sum;
        
        if (sum>b)
        {
            break;
        }
        else if (sum<a)
        {
            continue;
        }
        else{    
            cout<<sum<<endl;
        }    
    } 
    return 0;
}