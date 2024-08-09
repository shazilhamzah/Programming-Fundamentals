/*This is a rock paper scissor game. Player 1 and Player 2 take their turns and whoever beats the other, wins!*/

#include <iostream>
using namespace std;
int main() {
    char p1,p2;
    
    do{
    cout<<"Enter 'p' for PAPER, 'r' for ROCK, 's' for SCISSORS"<<endl;
    cout<<"Player 1: ";
    cin>>p1;
    cout<<endl;
    cout<<"Player 2: ";
    cin>>p2;
    cout<<endl;
    }while((p1!='r' && p1!='p' && p1!='s') || (p2 != 'r' && p2 != 'p' && p2 != 's'));
    
    
    if(p1=='r' && p2=='s'){
        cout<<"Player one wins. Rock smashes scissor!"<<endl;
    }
    else if(p1=='r' && p2=='p'){
        cout<<"Player two wins. Paper catches rock!"<<endl;
    }
    else if(p1==p2){
        cout<<"Tied!"<<endl;
    }
    else if(p1=='p' && p2=='s'){
        cout<<"Player 2 wins. Scissor cuts paper!"<<endl;
    }
    else if(p1=='p' && p2=='r'){
        cout<<"Player 1 wins. Paper catches rock!"<<endl;
    }
    else if(p1=='s' && p2=='r'){
        cout<<"Player 2 wins. Rock smashes scissor!"<<endl;
    }
    else if(p1=='s' && p2=='p'){
        cout<<"Player 1 wins. Scissor cuts paper!"<<endl;
    }
    else{
        cout<<"Invalid!!!"<<endl;
    }
    return 0;
}