//Program to find LCM of two numbers using GCD or HCF
#include <iostream>
using namespace std;

int main(){
    int a,b,min,gcd,lcm;
    
    //Taking input and checking for invalid inputs and zero
    do{
        cout<<"Enter first number: ";
        cin>>a;
        cout<<"Enter second number: ";
        cin>>b;
        cout<<endl;

        if(a<0 || b<0){
            cout<<"Enter unsigned numbers!"<<endl;
        }
        else if(a==0 || b==0){
            cout<<"LCM of "<<a<<" and " <<b<<" is: 0";
            return 0;
        }
        
        
        
    }while(a<=0 || b<=0);
    
    //Finding Lowest value of 'a' and 'b'
    if(a>b){
        min=b;
    }
    else{
        min=a;
    }
    
    //Finding GCD
    for(int i=min;i>0;i--){
        if(a%i==0 && b%i==0){
            gcd=i;
            break;
        }
        
    }
    
    //Finding LCM
    lcm=(a*b)/gcd;
    cout<<"LCM of "<<a<<" and "<<b<<" is: "<<lcm<<endl; 
    
}