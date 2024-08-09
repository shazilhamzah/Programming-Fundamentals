/*Given an array of integers, print and sort the array in such a way that the first element is first maximum
and second element is first minimum and so on.*/

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
    int temp[100];

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    int j=size-1,k=0;
    for (int i = 0; i<j ; i++)
    {
        temp[k]=arr[j];
        temp[k+1]=arr[i];
        j--;
        k+=2;
    
    }

    for (int i = 0; i < size; i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
}
