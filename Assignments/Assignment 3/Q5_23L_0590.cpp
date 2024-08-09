/*You are given an array and an index. You have to add an element at the given index of the given array and
print the new array .*/

#include <iostream>
using namespace std;

int input(int arr[]){
int i=0,n,size=0;
    do
    {
        cout<<"Enter a number: (-1 to exit) "; cin>>n;
        if (n==-1)
        {
            break;
        }
        arr[i]=n;
        i++;
        size++;
    } while (i<100);
    

    return size;
}
int main()
{
    int arr[100];
    int size=input(arr);
    int add,index;
    cout<<"Enter a number which you want to add: "; cin>>add;
    cout<<"Enter an index where you want to add: "; cin>>index;

    arr[index]=arr[index]+add;

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}