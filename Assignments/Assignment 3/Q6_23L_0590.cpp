/*Write a program which sorts the given data with respect to their frequency.*/

#include <iostream>
using namespace std;

bool isUnique(int arr[], int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return false;
        }
    }
    return true;
}

int input(int arr[]){
    int i=0,n,size=0;
    do
    {
        cout<<"Enter a number: (-99 to exit) "; cin>>n;
        if (n==-99)
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
    int Us[100];
    int frequency[100];


    cout<<endl;
    cout<<endl;
    
    // FINDING DISTINCT ELEMENTS AND PRINTING
    int distinct = 0;
    for (int i = 0; i < size; ++i) {
        if (isUnique(Us, distinct, arr[i])) {
            Us[distinct++] = arr[i];
        }
    }
    cout << "Distinct elements: ";
    for (int i = 0; i < distinct; ++i) {
        cout << Us[i] << "  ";
    }


    

    // FINDING FREQUENCY OF EACH DISTINCT ELEMENT
    for (int i = 0; i < distinct; i++)
    {
        frequency[i]=0;
    }
    
    for (int i = 0; i < distinct; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Us[i]==arr[j])
            {
                frequency[i]++;
            }
                
        }
            
    }

    // PRINTING FREQUENCY ARRAY
    cout<<endl<<"Frequencies: ";
    for (int i = 0; i < distinct; i++)
    {
        cout<<frequency[i]<<"  ";
    }



    // MAKING AND PRINTING SORTED US ARRAY USING BUBBLE SORT
    int sortedUs[100];
    for (int i = 0; i < distinct - 1; ++i) {
        for (int j = 0; j < distinct - i - 1; ++j) {
            if (frequency[j] < frequency[j + 1]) {
                swap(frequency[j], frequency[j + 1]);
                swap(Us[j], Us[j + 1]);
            }
        }
    }
    cout<<endl;
    cout<<"Sorted array is: ";
    for (int i = 0; i < distinct; i++)
    {
        cout<<Us[i]<<"  ";
    }

    // ELEMENTS IN NEW-D ARRAY AND PRINTING
    int dIndex=0;
    int newDArray[100];
    for (int i = 0; i < distinct; i++)
    {
        for (int j = 0; j < frequency[i]; j++)
        {
            newDArray[dIndex]=Us[i];
            dIndex++;
        }   
    }
    
    cout<<endl;
    cout<<"NewDArray is: ";
    for (int i = 0; i < size; i++)
    {
        cout<<newDArray[i]<<"  ";
    }
    
    

    return 0;
}