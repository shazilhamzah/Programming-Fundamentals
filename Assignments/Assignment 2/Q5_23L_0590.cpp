//Program to count even and odd numbers

#include <iostream>
using namespace std;
int main(){
    int n,evenCount=0,oddCount=0;
    do{
        cout<<"Enter a number: ";
        cin>>n;
        if(n==-1){
            break;
        }
        else if(n%2==0){
            evenCount++;
        }
        else{
            oddCount++;
        }
    }while(n!=-1);
    
    cout<<endl<<"Even numbers are = "<<evenCount;
    cout<<endl<<"Odd numbers are = "<<oddCount;
}