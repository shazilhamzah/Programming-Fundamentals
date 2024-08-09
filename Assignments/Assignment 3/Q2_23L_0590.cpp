/*Take an input array and display disctinct elements in increasing order and unique elements in decreasing order*/

#include<iostream>
using namespace std;

bool isUnique(int arr[],int n,int index,int input){
    for (int j = 0; j < input; j++)
    {
        if (index==j)
        {
            continue;
        }
        else if (n==arr[j])
        {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    //DECLARING VARIABLES
    int abc=0;
	const int size=20;
    
	int distinct=0;
	int unique=0;
    int n;
    int input =0;



    //DECLARING ARRYS
	int DistinctArray[size];
	int UniqueArray[size];
    int arr[size];


    cout<<"Enter maximum of 20 numbers (Enter -99 to quit!)"<<endl;
    do
    {
        //INPUT OF NUMBERS
        cout<<"Enter a number: "; cin>>n;
        arr[input]=n;
        input++;
        if (n==-99)
        {
           break;
        }
        

        //CHECKING IF ELEMENT IS DISTINCT
        bool elementIsDistinct = true;
        for (int i = 0; i < distinct; i++)
        {
            if (DistinctArray[i]==n)
            {
                elementIsDistinct=false;
                break;
            }
            
        }


        //IF ELEMENT IS DISTINCT... IT IS STORED IN AN DISTINCT ARRAY
        if (elementIsDistinct)
        {
            DistinctArray[distinct]=n;
            distinct++;
        }
    } while (input<20);


    // SORTING DISTINCT ARRAY USING SELECTION SORT
    int i, j, min_idx;
    for (i = 0; i < distinct - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < distinct; j++) {
            if (DistinctArray[j] < DistinctArray[min_idx])
                min_idx = j;
        }
        if (min_idx != i){
            swap(DistinctArray[min_idx], DistinctArray[i]);
        }
    }

    



    //PRINTING DISTINCT ARRAY
    cout<<endl<<"(Part A) Distinct array is: "; 
    for (int  m = 0; m < distinct; m++)
    {
        cout<<DistinctArray[m]<<" ";
    }

    

    
    
    
    
    // ASSIGNING ELEMENTS TO UNIQUE ARRAY
    int uniqueIndex=0;
    for (int i = 0; i < input-1; i++)
    {
        if (isUnique(arr,arr[i],i,input-1))
        {
            UniqueArray[uniqueIndex]=arr[i];
            uniqueIndex++;
            unique++;
        }
    }
    
    // SORTING UNIQUE ARRAY
    for (i = 0; i < unique - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < unique; j++) {
            if (UniqueArray[j] > UniqueArray[min_idx])
                min_idx = j;
        }
        if (min_idx != i){
            swap(UniqueArray[min_idx], UniqueArray[i]);
        }
    }
    

    // PRINTING UNIQUE ARRAY
    cout << endl << "(Part B) Unique array is: ";
    for (int i = 0; i < unique; i++) {
        cout << UniqueArray[i] << " ";
    }
}
