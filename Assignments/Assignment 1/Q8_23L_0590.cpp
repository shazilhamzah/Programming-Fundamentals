/*This program forms four type of shapes using only four loops and a single cout statement for "*""*/

#include<iostream>
using namespace std;
int main(){
    cout<<endl;
    cout<<"(a)"<<endl<<endl;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"(b)"<<endl<<endl;
    for (int c = 10; c > 0; c--)
    {
        for(int d=1;d<=c;d++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"(c)"<<endl<<endl;
    for (int x = 10; x > 0; x--)
    {
        for(int y=0; y<10-x; y++)
        {
            cout<<" ";
        }
        for (int z = 1; z <= x; z++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
    cout<<endl;
    cout<<"(d)"<<endl<<endl;
    for (int k = 1; k <= 10; k++)
    {
        for (int a = 1; a <= 10-k; a++)
        {
            cout<<" ";
        }
        for (int b = 1; b <=k; b++)
        {
            cout<<"*";
        }
        cout<<endl;
        
        
    }
    
    
    
}