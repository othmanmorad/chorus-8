#include <iostream>
#include <string>
using namespace std;


//problem55

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


short ReadVactionDays()
{
    short VactionDays;
    cout << "Please Enter a vaction Days ";
    cin >> VactionDays;
    return VactionDays;
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


bool IsLastMonth(short Month)
{
    return (Month == 12);
}

bool IsLastDay(sDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}




string NameDay(short DayOfWeekOrder)
{
    string Day[7] =
    {
        "Sun","Mon","Tue","Wed","Thu","Fri","Satr"

    };

    return Day[DayOfWeekOrder];
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






bool IsWeekEnd(sDate Date)
{
    return DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 5;
}

bool IsBusinessDay(sDate Date)
{
    // return DayOfWeekOrder(Date) != 6 && DayOfWeekOrder(Date) != 5;

    return(!IsWeekEnd(Date));
}


sDate CalculateVactionReturnDate(sDate DateFrom, short VactionDays)
{
    short WeekEndCount = 0;


    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaceDateByOneDay(DateFrom);
    }

    for (short i = 1;i <= VactionDays + WeekEndCount;i++)
    {

        if (IsWeekEnd(DateFrom))
        {
            WeekEndCount++;

        }
        DateFrom = IncreaceDateByOneDay(DateFrom);

    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaceDateByOneDay(DateFrom);
    }

    return DateFrom;
}


int main()
{
    sDate Date = ReadFullDate();

    short VactionDays = ReadVactionDays();


    Date = CalculateVactionReturnDate(Date, VactionDays);
    cout << "\nReturn Date : , " << NameDay(DayOfWeekOrder(Date));
    cout << "\t" << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}