/*This program is written to arrange a set of integers in ascending and descending order
Created this program using only if and else if conditional statements*/

#include<iostream>
using namespace std;
int main(){
    int a,b,c;

    cout<<"Enter first integer: "<<endl;
    cin>>a;                                    //Input first integer
    cout<<"Enter second integer: "<<endl;
    cin>>b;                                    //Input second integer
    cout<<"Enter third integer: "<<endl;
    cin>>c;                                    //Input third integer

    //Defining conditions
    
    if (c>=a && b>=c)
    {
        cout<<"Integers in ascending order are:"<<" "<<c<<" "<<b<<" "<<a<<endl;
        cout<<"Integers in descending order are:"<<" "<<a<<" "<<b<<" "<<c<<endl;
    }
    else if (b>=a && a>=c)
    {
        cout<<"Integers in ascending order are:"<<" "<<c<<" "<<a<<" "<<b<<endl;
        cout<<"Integers in descending order are:"<<" "<<b<<" "<<a<<" "<<c<<endl;
    }
    else if (c>=a && a>=b)
    {
        cout<<"Integers in ascending order are:"<<" "<<b<<" "<<a<<" "<<c<<endl;
        cout<<"Integers in ascending order are:"<<" "<<c<<" "<<a<<" "<<b<<endl;
    }
    else if (c>=b && b>=a)
    {
        cout<<"Integers in ascending order are:"<<" "<<a<<" "<<b<<" "<<c<<endl;
        cout<<"Integers in ascending order are:"<<" "<<c<<" "<<b<<" "<<a<<endl;
    }
    else if(a>=c && c>=b)
    {
        cout<<"Integers in ascending order are:"<<" "<<b<<" "<<c<<" "<<a<<endl;
        cout<<"Integers in ascending order are:"<<" "<<a<<" "<<c<<" "<<b<<endl;
    }
    else if(a>=b && b>=c){
        cout<<"Integers in ascending order are:"<<" "<<c<<" "<<b<<" "<<a<<endl;
        cout<<"Integers in ascending order are:"<<" "<<a<<" "<<b<<" "<<c<<endl;
    }
    else
    {
        cout<<"No luck!"<<endl;
    }
    return 0;
    
    
}