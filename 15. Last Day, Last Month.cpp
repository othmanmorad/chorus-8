#include <iostream>
#include <string>

using namespace std;
struct sDate
{
    short Year;
    short Mounth;
    short Day;
};

short ReadYear()
{
    short Year;
    cout << "\nEnter the year " << endl;
    cin >> Year;
    return Year;
}

short ReadMounth()
{
    short Year;
    cout << "\nEnter the Mounth " << endl;
    cin >> Year;
    return Year;
}

short ReadDay()
{
    short Year;
    cout << "\nEnter the day " << endl;
    cin >> Year;
    return Year;
}


sDate ReadFullDate()
{
    sDate Date;
    Date.Year = ReadYear();

    Date.Mounth = ReadMounth();

    Date.Day = ReadDay();

    return Date;
}

bool IsLastMonthInYear(sDate Date )
{
    
    return(Date.Mounth == 12);

}
bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short NumberOfDaysInMounth(short Mounth, short Year)
{
    short Days[12] = { 31, 28 , 31 , 30 , 31 , 30,31,31,30 ,31 ,30,31 };

    return (Mounth == 2) ? (IsLeapYear(Year)) ? 29 : 28 :
        Days[Mounth - 1];
}

bool IsLastDayInMonth(sDate Date)
{
    return(Date.Day == NumberOfDaysInMounth(Date.Mounth, Date.Year));
   

}


int main()
{
    sDate Date = ReadFullDate();
    cout << "\n\n\n" << endl;
  
    if (IsLastDayInMonth(Date))
    {
        cout << "\nYes , Day is the last Day in Month";
    }
    else
    {
        cout << "\nNo ,Day is not last Day in Month ";
    }


    if (IsLastMonthInYear(Date))
    {
        cout << "\nYes , Month is the last month in year";
    }
    else
    {
        cout << "\nNo ,Month is not last month in year ";
    }


    system("pause>0");

}