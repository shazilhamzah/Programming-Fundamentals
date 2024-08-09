/*This is a simple C++ program to detect whether the given points form a pythogorean triplet or not. */

#include <iostream>
using namespace std;
int main() {
    int a,b,c;

    cout<<"Enter first number: ";
    cin>>a;
    cout<<endl;

    cout<<"Enter second number: ";
    cin>>b;
    cout<<endl;

    cout<<"Enter third number: ";
    cin>>c;
    cout<<endl;

    if((c*c)==(a*a)+(b*b) || (a*a)==(c*c)+(b*b) || (b*b)==(a*a)+(c*c)){
    	cout<<"Numbers are pythagorean triple!"<<endl;
    }
    else{
	    cout<<"Not a pythagorean triple!"<<endl;
    }



    return 0;
}