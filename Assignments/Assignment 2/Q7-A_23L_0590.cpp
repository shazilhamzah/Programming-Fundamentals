#include <iostream>
using namespace std;
int main() {
    //Part A
    int k,fib,a=0,b=1,sum=0;
    do{
        cout<<"How many values you want to ask? ";
        cin>>k;
        if(k<0){
            cout<<"Enter a valid number!"<<endl;
        }
    }while(k<0);
    
    for(int i=0;i<k;i++){
        int j=1,sum=0,a=0,b=1;
        do{
            cout<<"Enter Febinacci you want to ask: ";
            cin>>fib;
            if(fib<=0){
                cout<<"Enter a valid number (>0)"<<endl;
            }
        }while(fib<=0);

        for(int l=2;true;l++){
            sum=a+b;
            a=b;
            b=sum;
            j++;
            if(j==fib){
                cout<<sum<<endl;
                break;
            }
        }
    }
    return 0;
}