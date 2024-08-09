/*Write a program that keeps on taking input from the user until the user enters -1 (at maximum 100 values)
and then sort the even index values, in increasing order and odd index values, in decreasing order.*/

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

    for (int i = 0; i < size-3; i+=2)
    {
        for (int j = i+2; j<size-1; j+=2)
        {
            if (arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

    for (int i = 1; i < size-2; i+=2)
    {
        for (int j = i+2; j<size; j+=2)
        {
            if (arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    
    // TEMP CHECK
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}