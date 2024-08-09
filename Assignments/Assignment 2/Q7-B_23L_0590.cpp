#include <iostream>
using namespace std;

int a=0,b=1,sum=0,k;
int main(){
    do{
        cout<<"Enter number upto which you want to find fibenacci: ";
        cin>>k;
        if(k<=0){
            cout<<"Enter a valid number!"<<endl;
        }
    }while(k<=0);
    cout<<a<<endl;
    cout<<b<<endl;
    for(int i=0;sum<k-1;i++){
        sum=a+b;
        a=b;
        b=sum;
        if(sum>=k){
            break;
        }
        cout<<sum<<endl;
        
    }
}