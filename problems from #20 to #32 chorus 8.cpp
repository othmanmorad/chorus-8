#include <iostream>
#include <string>
using namespace std;

//problems from 20 to 32


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



struct  sDate {
    short Year;
    short Month;
    short Day;
};


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

sDate IncreaceDateByXDay(short Days, sDate Date)
{
    for (short i = 1;i <= Days;i++)
    {
        Date = IncreaceDateByOneDay(Date);
    }
    return Date;
}
sDate IncreaceDateByOneWeek(sDate Date)
{
    for (short i = 1;i <= 7;i++)
    {
        Date = IncreaceDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaceDateByXWeek(short Weeks, sDate Date)
{
    for (short i = 1;i <= Weeks;i++)
    {
        Date = IncreaceDateByOneWeek(Date);
    }
    return Date;
}
sDate IncreaceDateByOneMonth(sDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;

    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate IncreaceDateByXMonth(short Month, sDate Date)
{
    for (short i = 1;i <= Month;i++)
    {
        Date = IncreaceDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaceDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}

sDate IncreaceDateByXYear(short Year, sDate Date)
{
    for (short i = 1;i <= Year;i++)
    {
        Date = IncreaceDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaceDateByXYearFaster(short Year, sDate Date)
{

    Date.Year += Year;

    return Date;
}

sDate IncreaceDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}

sDate IncreaceDateByXDecads(short Decads, sDate Date)
{
    for (short i = 1;i <= Decads;i++)
    {
        Date = IncreaceDateByOneDecade(Date);
    }
    return Date;
}


sDate IncreaceDateByXDecadsFaster(short Decads, sDate Date)
{

    Date.Year += Decads * 10;

    return Date;
}



sDate IncreaceDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaceDateByXCentury(short century, sDate Date)
{
    for (short i = 1;i <= century;i++)
    {
        Date = IncreaceDateByOneCentury(Date);
    }
    return Date;
}


sDate IncreaceDateByXCenturyFaster(short century, sDate Date)
{

    Date.Year += century * 100;

    return Date;
}

sDate IncreaceDateByOneMillnnium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();


    Date = IncreaceDateByOneDay(Date);

    cout << "\n01-Adding one day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = IncreaceDateByXDay(10, Date);
    cout << "\n02-Adding 10 days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = IncreaceDateByOneWeek(Date);
    cout << "\n03-Adding one week is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXWeek(10, Date);

    cout << "\n04-Adding 10 week is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = IncreaceDateByOneMonth(Date);
    cout << "\n05-Adding one Month is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXMonth(5, Date);
    cout << "\n06-Adding 5 Months is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;





    Date = IncreaceDateByOneYear(Date);
    cout << "\n07-Adding one Year is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXYear(10, Date);
    cout << "\n08-Adding 10 Year is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXYearFaster(10, Date);
    cout << "\n09-Adding 10 Year is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = IncreaceDateByOneDecade(Date);
    cout << "\n10-Adding one decade is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXDecads(10, Date);
    cout << "\n11-Adding 10 Decads is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXDecadsFaster(10, Date);
    cout << "\n12-Adding 10 Decads is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;





    Date = IncreaceDateByOneCentury(Date);
    cout << "\n13-Adding one century is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXCentury(10, Date);
    cout << "\n14-Adding 10 century is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaceDateByXCenturyFaster(10, Date);
    cout << "\n15-Adding 10 century is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = IncreaceDateByOneMillnnium(Date);
    cout << "\n16-Adding one Millnnium is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}
