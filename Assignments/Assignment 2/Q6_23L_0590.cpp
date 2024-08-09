//Program to find sum of whole numbers from 500 to 3000 which are multiple of 3 or 5 but not both
#include <iostream>
using namespace std;
int main() {
    int sum=0;
    for(int i=501;i<3000;i++){
        if(i%3==0 && i%5==0){
            continue;
        }
        else if(i%3==0){
            sum+=i;
        }
        else if(i%5==0){
            sum+=i;
        }
    }
    cout<<endl;
    cout<<"The sum is = "<<sum<<endl;
    return 0;
}