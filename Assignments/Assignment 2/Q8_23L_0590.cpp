#include <iostream>
using namespace std;

int birthDay,birthMonth,birthYear,currentDay,currentMonth,currentYear,aDays,aMonths,aYears,totaldays;
bool valid=false,leapyearCurrent=false,leapyearBirth=false;
bool leapYear(int year);
int daysinMonth(int month,int year);


//Checking number of days in month
int daysinMonth(int month,int year){
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 ||month==12)
    {
        totaldays=31;
    }
    else if (month==4 || month==6 || month ==9 || month==11)
    {
        totaldays=30;
    } 
    else if (month==2)
    {
        if (leapYear(year))
        {
            totaldays=29;
        }
        else{
            totaldays=28;
        }
    }
    return totaldays;
}


//Checking for a leap year
bool leapYear(int year){
    bool leapyearcheckbool=false;
    if (year%4==0 || year%100==0)
        {
            leapyearcheckbool = true;
        }
    return leapyearcheckbool;
}



//Main function
int main()
{
    do
    {
        cout<<"Enter current day: ";
        cin>>currentDay;
        cout<<"Enter current month: ";
        cin>>currentMonth;
        cout<<"Enter current year: ";
        cin>>currentYear;
        cout<<"Enter birth day: ";
        cin>>birthDay;
        cout<<"Enter birth month: ";
        cin>>birthMonth;
        cout<<"Enter birth year: ";
        cin>>birthYear;


        //Checking for validations

        if (currentDay<=0 || birthDay<=0 || birthMonth<=0 || currentMonth<=0 || birthYear<=0 || currentYear<=0 || birthMonth>12 || currentMonth>12 || birthYear>currentYear)
        {
            cout<<"Enter invalid date."<<endl;
            valid=true;                                     
        }

        else if (currentDay > daysinMonth(currentMonth,currentYear) ||
                   birthDay > daysinMonth(birthMonth,birthYear)) {
            cout << "Enter a valid date." << endl;
            valid = true;
        }
    } while (valid);

    aYears=currentYear-birthYear;
    aMonths=currentMonth-birthMonth;                        //Basic calculations
    aDays=currentDay-birthDay;

    if (aDays<0)
    {
        aMonths--;
        aDays = aDays+daysinMonth(birthMonth,birthYear);    //Taking month carry
    }

    if (aMonths<0)
    {                       
        aYears--;                                           //Taking year carry
        aMonths=aMonths+12;
    }

    cout<<"Your age is: "<<aYears<<" years, "<<aMonths<<" months and,  "<<aDays<<" days."<<endl;

    return 0;
}