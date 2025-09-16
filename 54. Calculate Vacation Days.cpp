#include<iostream>
#include<string>
using namespace std;





//problem54

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

bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

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
        "Sun","Mon","Tue","Wed","Thu","Fri","Satr"

    };

    return Day[DayOfWeekOrder];
}



bool IsWeekEnd(sDate Date)
{
    return DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 5;
}



short CalculateVactionDays(sDate DateFrom, sDate DateTo)
{
    int Days = 0;
    while (IsDate1BeforDate2(DateFrom, DateTo))
    {
        if (!IsWeekEnd(DateFrom))

            Days++;
        DateFrom = IncreaceDateByOneDay(DateFrom);

    }
    return Days;
}





int main()
{

    cout << "\nVaction starts :" << endl;
    sDate DateStart = ReadFullDate();

    cout << "\n\nVaction Ends\n\n";

    sDate DateEnds = ReadFullDate();



    cout << "\n\nVaction from " << NameDay(DayOfWeekOrder(DateStart)) << "  "
        << DateStart.Day << "/" << DateStart.Month << "/" << DateStart.Year << endl;

    cout << "\n\nVaction to " << NameDay(DayOfWeekOrder(DateEnds)) << "  "
        << DateEnds.Day << "/" << DateEnds.Month << "/" << DateEnds.Year << endl;



    cout << "\n\nActucal Vaction Days is : " << CalculateVactionDays(DateStart, DateEnds);



}