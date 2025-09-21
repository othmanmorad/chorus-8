#include<iostream>
#include<string>
using namespace std;


///problem62


struct  sDate
{
    short Year;
    short Month;
    short Day;
};






short ReadYear()
{
    short Year;
    cout << "Enter the Year ";
    cin >> Year;
    return Year;
}


short ReadMonth()
{
    short Month;
    cout << "Enter the Month ";
    cin >> Month;
    return Month;
}


short ReadDay()
{
    short Day;
    cout << "Enter the Day ";
    cin >> Day;
    return Day;
}



sDate ReadFullDate()
{
    sDate Date;
    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay();

    return Date;

}


bool IsLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);

}


short NumberOfDaysInMonth(short Month, short Year)
{
    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool IsValidDate(sDate Date)
{
    //Method 1
   // return ((Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year)&&Date.Day>=1)&& (Date.Month <= 12 && Date.Month >= 1));

    //Method 2
    if (Date.Day < 1 || Date.Day>31)
        return false;

    if (Date.Month > 12 || Date.Month < 1)
        return false;

    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)

                return false;

        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }
    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
        return false;

    return true;

}

int main()
{
    sDate Date = ReadFullDate();


    if (IsValidDate(Date))
    {
        cout << "\nYes,Date is a valide date.";
    }
    else
    {
        cout << "\nNo,Date is Not a valide date.";
    }
}
