/*You are given an array of Prime, Fibonacci and Non-PrimeFibonacci (the numbers neither prime nor fibonacci) numbers in random order. Segregate all Fibonacci on left side, Prime on right side and Non-
PrimeFibonacci in the middle of the array. If a number is Prime and Fibonacci both, it's your choice to treat it as a Prime or Fibonacci number. Also find the MinimumSwapsCount - the number of swaps required to
get the final array.*/

#include <iostream>
#include <cmath>
using namespace std;

bool fibenacciCheck(int n){
    bool check=false; int a=0,b=1,sum=a+b;
    if (n==a || n==b)
    {
        return true;
    }
    
    for (int i = 0; sum <= n; i++)
    {
        a=b;
        b=sum;
        sum=a+b;
        if (sum==n )
        {
            check=true;
        }
        
    }
    
    return check;
}
bool primeCheck(int n){
    if (n==1)
    {
        return false;
    }
    else if (n==2)
    {
        return true;
    }

    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
bool nonFibnonPrime(int n){
    if (fibenacciCheck(n)==false && primeCheck(n)==false)
    {
        return true;
    }
    return false;
}
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
    int fib=0,prime=0,non=0,minSwapCount=0;
    
    int arr[100];
    int size=input(arr);
    int temp[100];
    
    // ARRANGING ELEMENTS
    for (int i = 0; i < size; i++)
    {
        if (fibenacciCheck(arr[i]))
        {
            fib++;
        }
        else if (primeCheck(arr[i])&&!fibenacciCheck(arr[i]))
        {
            prime++;
        }
        else if (nonFibnonPrime(arr[i]))
        {
            non++;
        }
    }

    
    
    int fibindex=0;
    for (int i = 0; i < size; i++)
    {
        if (fibindex==fib)
        {
            break;
        }
        else if (fibenacciCheck(arr[i]))
        {
            swap(arr[i],arr[fibindex]);
            minSwapCount++;
            fibindex++;
        }
    }


    int nonindex=fibindex;
    for (int i = fib; i < size; i++)
    {
        if (nonindex==non+fib)
        {
            break;
        }
        else if (nonFibnonPrime(arr[i]))
        {
            swap(arr[i],arr[nonindex]);
            minSwapCount++;
            nonindex++;
        }
    }
    

    // Array Return
    cout<<"Sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl<<"Min Swap Count is: "<<minSwapCount;
    return 0;
}
