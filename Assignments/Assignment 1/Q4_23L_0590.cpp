/*This program takes three points as coordinates and determine whether they form a triangle or not.
And if they form, whether it is scalene,isoceles,right or equilateral.*/

#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    //Input for points
    
    float ax,ay,bx,by,cx,cy;
    float side1,side2,side3;
    
    input:
    cout<<"Enter first point"<<endl;
    cin>>ax;
    cin>>ay;
    cout<<"Enter second point"<<endl;
    cin>>bx;
    cin>>by;
    cout<<"Enter third point"<<endl;
    cin>>cx;
    cin>>cy;

    //Calculating sides
    
    side1 = sqrt((pow((by-ay),2))+((pow((bx-ax),2))));
    side2 = sqrt((pow((cy-by),2))+((pow((cx-bx),2)))); 
    side3 = sqrt((pow((cy-ay),2))+((pow((cx-ax),2))));
    cout<<endl;
    cout<<"Side 1 is: "<<side1<<endl;
    cout<<"Side 2 is: "<<side2<<endl;
    cout<<"Side 3 is: "<<side3<<endl;
    
    cout<<endl;

    
    //Checking for existance
    if ((side1+side2>side3)||(side1+side3>side2)||(side2+side3>side1))
    {
        cout<<"Triangle exists!"<<endl;

    }
    else
    {
        cout<<"Trinagle doesn't exxist. Enter coordinates again!"<<endl;
        goto input;
    }
    //Checking for sides
    if (side1==side2 && side2==side3)
    {
        cout<<"Equilateral.";
    }
    else if (side1==side2 || side2==side3 || side1==side3)
    {
        if (pow(side1,2) == (pow(side2, 2) + pow(side3, 2)) || (pow(side2, 2) == pow(side1, 2) + pow(side3,2) || (pow(side3, 2) == pow(side1, 2) + pow(side2, 2)), 2))
             
        {
            cout<<"Right.";
        }
        else
        {
            cout<<"Isoceles.";
        }
    
    }
    else
    {
        cout<<"Scalene.";
    }
    
    

        
    


    
    
    
    
    
    
    
    return 0;
}