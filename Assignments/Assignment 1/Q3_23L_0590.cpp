/*This program converts 6 digit or less integers into strings using for loops and if-else conditions.*/


#include <iostream>
#include<math.h>
using namespace std;


int main()
{
    int num,j;
    
    int a=0;
    
    
    do
    {

        if (num>999999)
        {
            cout<<"No number greater than six digits is allowed!"<<endl;
        }
        cout<<endl;
        cout<<"Enter a 6-digit number: ";
        cin>>num;
        
    } while (num>999999);
    if (num==0)
    {
        cout<<"zero"<<endl;
    }
    
    int b=num;
    while(b>0)
    {
        a++;
        b=b/10;
    };
    int fl=pow(10,(a-1));
    for (int i = 0; i < a ; i++)
    {
        
        j=num/fl; //Extracting first digit
        num=num%fl; //Removing first digit
        fl=fl/10;
       
        switch (j)
        {
        case 1:
            cout<<"one ";
            break;

        case 2:
            cout<<"two ";
            break;

        case 3:
            cout<<"three ";
            break;

        case 4:
            cout<<"four ";
            break;

        case 5:
            cout<<"five ";
            break;

        case 6:
            cout<<"six ";
            break;

        case 7:
            cout<<"seven ";
            break;

        case 8:
            cout<<"eight ";
            break;

        case 9:
            cout<<"nine ";
            break;

        case 0:
            cout<<"zero ";
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
}
