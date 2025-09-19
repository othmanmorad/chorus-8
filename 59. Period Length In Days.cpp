#include <iostream>
#include <string>
using namespace std;

//problem 59

struct  sDate
{
    short Year;
    short Month;
    short Day;
};


struct sPeriod
{

    sDate StartDate;
    sDate EndDate;

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

sPeriod ReadPeriod()
{
    sPeriod Period;

    cout << "\nEnter Start date \n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End date \n ";
    Period.EndDate = ReadFullDate();

    return Period;

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


bool IsLastMonth(short Month)
{
    return (Month == 12);
}

bool IsLastDay(sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}


sDate IncreaceDateByOneDay(sDate Date)
{
    if (IsLastDay(Date))
    {
        if (IsLastMonth(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}


bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int GetDiffrinceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaceDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
{
    return  GetDiffrinceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}




int main()
{
    cout << "\nEnter period 1 \n";
    sPeriod Period = ReadPeriod();



    cout << "\nPeriod length is : " << PeriodLengthInDays(Period);
    cout << "\nPeriod length is (include End day): " << PeriodLengthInDays(Period, true);

}

