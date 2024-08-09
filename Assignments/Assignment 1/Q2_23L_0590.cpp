/*
This program is written for a resturant app. Its funtions are the following:
1) Taking order from the customer and asking for quantity
2) Asking for certain currencies and conversion into corresponding currencies
3)Displating salesTax and subTotals
Created this program using if, switch statements and while loops
*/

#include<iostream>
using namespace std;
int main(){
    //Declaration of variables
    int dish,cur;
    float quant,mealPrice,salesTax,mealPrice1,subTotal;
    
    
    //Presenting the menu
    order:
    cout<<"Welcome to our resturant!"<<endl;
    cout<<"We have following meals in our menu: "<<endl;
    cout<<"Code      Dish                Price per kg"<<endl;
    cout<<"1         Chicken Handi       1800"<<endl;
    cout<<"1         Chicken Karahi      1900"<<endl;
    cout<<"3         Chicken Kabab       2300"<<endl;
    cout<<"4         Mutton Karahi       2400"<<endl;
    cout<<"5         Malai Boti          430"<<endl;
    cout<<endl;
    do
    {
        cout<<"Enter meal code to order: ";
        cin>>dish;
        cout<<endl;
        if (dish<=0 || dish>5)
        {
            cout<<"Invalid dish code. Enter again.."<<endl;
        }
        
    } while (dish<=0 || dish>5);
    
    


    //Asking for quantity
    cout<<"How much of meal(in kilograms) do you want? ";
    cin>>quant;

    //Calculating Meal Price
    switch (dish)
    {
    case 1:
        mealPrice1 = quant*1800;
        break;
    case 2:
        mealPrice1 = quant*1900;
        break;
    case 3:
        mealPrice1 = quant*2300;
        break;
    case 4:
        mealPrice1 = quant*2400;
        break;
    case 5:
        mealPrice1 = quant*430;
        break;
    default:
        break;
    }

    //Asking for currency
    currency:
    cout<<"In which currency do you want to pay?"<<endl;
    cout<<"1. USD"<<endl;
    cout<<"2. PKR"<<endl;
    cout<<"3. EUR"<<endl;
    do
    {
        cout<<"Enter currency code: ";
        cin>>cur;
        if (cur>3 || cur<=0)
        {
            cout<<"Invalid currency. Enter again.."<<endl;
        }
        
    } while (cur>3 || cur<=0);
    
    

    //Currency Conversion
    switch (cur)
    {
    case 1:
        mealPrice = mealPrice1/165;
        break;
    case 2:
        mealPrice = mealPrice1;
        break;
    case 3:
        mealPrice = mealPrice1/193;
        break;
    default:
        break;
    }

    //Calculating salesTax
    if (mealPrice1<=1000)
    {
        salesTax = 0;
    }
    else if (mealPrice1>1000 && mealPrice1<=3000)
    {
        salesTax = mealPrice*0.02;
    }
    else
    {
        salesTax = mealPrice*0.05;
    }

    //Calculating Total
    subTotal = mealPrice+salesTax;
    cout<<"Your meal Price is: "<<mealPrice<<endl;
    cout<<"Your sales tax is: "<<salesTax<<endl;
    cout<<"Your SubTotal is: "<<subTotal<<endl;
    
    
    


    
    


}

