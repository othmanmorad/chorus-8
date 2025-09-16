#include <iostream>
#include <string>

using namespace std;
//pribems from 47 to 53
#pragma warning(disable : 4996)
struct  sDate
{
    short Year;
    short Month;
    short Day;
};



short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a - 2);

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short DayOfWeekOrder(sDate Date)
{
    return (DayOfWeekOrder(Date.Day, Date.Month, Date.Year));
}


string NameDay(short DayOfWeekOrder)
{
    string Day[7] =
    {
        "Sun","Mon","Tue","Wed","The","Fri","Satr"

    };

    return Day[DayOfWeekOrder];
}

sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}




bool IsEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}


bool IsWeekEnd(sDate Date)
{
    return DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 5;
}


bool IsBusinessDay(sDate Date)
{
    // return DayOfWeekOrder(Date) != 6 && DayOfWeekOrder(Date) != 5;

    return(!IsWeekEnd(Date));
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


bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

sDate IncreaceDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
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
short NumberOfDaysFromBegningTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 1;i <= Month - 1;i++)
    {
        TotalDays += NumberOfDaysInMonth(i, Year);

    }
    TotalDays += Day;
    return TotalDays;
}
short NumberOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
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


short DaysUntilTheEndOfWeek(sDate Date)
{
    // short Day = 0;
    // while (DayOfWeekOrder(Date) != 6)
    // {
    //     Day++;
    //     Date= IncreaceDateByOneDay(Date);
    // }
    // return Day;


     //Method 2
    return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(sDate Date)
{
    // short Day = 0;
    // while ( Date.Day!= NumberOfDaysInMonth(Date.Month, Date.Year))
    // {
    //     Day++;
    //     Date = IncreaceDateByOneDay(Date);
    // }
    // return Day;


    //Method 2
    sDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDiffrinceInDays(Date, EndOfMonthDate, true);

}
short DaysUntilTheEndOfYear(sDate Date)
{

    //return NumberOfDaysInYear(Date.Year)-  NumberOfDaysFromBegningTheYear(Date.Day,Date.Month,Date.Year);


    //Method 2

    sDate EndOfYearDate;

    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDiffrinceInDays(Date, EndOfYearDate, true);
}

int main()
{
    sDate Date = GetSystemDate();


    cout << "Today is " << NameDay(DayOfWeekOrder(Date))
        << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    cout << "\n\nIs it End of Week ? ";
    if (IsEndOfWeek(Date))
    {
        cout << "\nYes it's end of week ";
    }
    else
    {
        cout << "\nNo Not end of week ";
    }



    cout << "\n\nIs it WeekEnd ? ";
    if (IsWeekEnd(Date))
    {
        cout << "\nYes it's a weekend ";
    }
    else
    {
        cout << "\nNo it is Not a weekend ";
    }


    cout << "\n\nIs it Business day ? ";
    if (IsBusinessDay(Date))
    {
        cout << "\nYes it's a business day ";
    }
    else
    {
        cout << "\nNo it is Not a business day ";
    }


    cout << "\n\nDays Until The End Of Week is : " << DaysUntilTheEndOfWeek(Date) << endl;
    cout << "\n\nDays Until The End Of Month is : " << DaysUntilTheEndOfMonth(Date) << endl;
    cout << "\n\nDays Until The End Of Year is : " << DaysUntilTheEndOfYear(Date) << endl;


}