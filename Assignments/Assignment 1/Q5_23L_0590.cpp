/*This program takes four points as coordiantes and a fifth point and check whether the fifth point is 
inside the rectangle or not*/

#include <iostream>
using namespace std;

int main()
{
    float ax,ay,bx,by,cx,cy,dx,dy,px,py;
    cout<<endl;
    cout<<"Enter coordinates in the following format: "<<endl<<endl;
    cout<<"d---------------c"<<endl;
    cout<<"|               |"<<endl;
    cout<<"|               |"<<endl;
    cout<<"|               |"<<endl;
    cout<<"a---------------b"<<endl;

    cout<<"Enter point ax: ";
    cin>>ax;
    cout<<endl;

    cout<<"Enter point ay: ";
    cin>>ay;
    cout<<endl;

    cout<<"Enter point bx: ";
    cin>>bx;
    cout<<endl;

    cout<<"Enter point by: ";
    cin>>by;
    cout<<endl;

    cout<<"Enter point cx: ";
    cin>>cx;
    cout<<endl;

    cout<<"Enter point cy: ";
    cin>>cy;
    cout<<endl;

    cout<<"Enter point dx: ";
    cin>>dx;
    cout<<endl;

    cout<<"Enter point dy: ";
    cin>>dy;
    cout<<endl;

    cout<<"Enter point px you want to check: ";
    cin>>px;
    cout<<endl;

    cout<<"Enter point py you want to check: ";
    cin>>py;
    cout<<endl;
            
    if (py<=cy && py>=by && px>=ax && px<=cx)
    {
        cout<<"Point is inside the rectangle!"<<endl;
    }
    else{
        cout<<"Point is not inside the rectangle!"<<endl;
    }
    return 0;
    
}




