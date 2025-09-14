#include <iostream>
#include <string>

using namespace std;



//problems from 33 to 46





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



struct  sDate
{
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




sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);

        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

sDate DecreaseDateByXDay(short Days, sDate Date)
{
    for (short i = 1;i <= Days;i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByOneWeek(sDate Date)
{
    for (short i = 1;i <= 7;i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXWeek(short Weeks, sDate Date)
{
    for (short i = 1;i <= Weeks;i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;

    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate DecreaseDateByXMonth(short Month, sDate Date)
{
    for (short i = 1;i <= Month;i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYear(short Year, sDate Date)
{
    for (short i = 1;i <= Year;i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearFaster(short Year, sDate Date)
{

    Date.Year -= Year;

    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecads(short Decads, sDate Date)
{
    for (short i = 1;i <= Decads;i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}


sDate DecreaseDateByXDecadsFaster(short Decads, sDate Date)
{

    Date.Year -= Decads * 10;

    return Date;
}



sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}

sDate DecreaseDateByXCentury(short century, sDate Date)
{
    for (short i = 1;i <= century;i++)
    {
        Date = DecreaseDateByOneCentury(Date);
    }
    return Date;
}


sDate DecreaseDateByXCenturyFaster(short century, sDate Date)
{

    Date.Year -= century * 100;

    return Date;
}

sDate DecreaseDateByOneMillnnium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();


    Date = DecreaseDateByOneDay(Date);

    cout << "\nDate After : " << endl;


    cout << "\n01-Subtracting one day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = DecreaseDateByXDay(10, Date);
    cout << "\n02-Subtracting 10 days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Subtracting one week is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeek(10, Date);

    cout << "\n04-Subtracting 10 weeks is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Subtracting one Month is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonth(5, Date);
    cout << "\n06-Subtracting 5 Months is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;





    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Subtracting one Year is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYear(10, Date);
    cout << "\n08-Subtracting 10 Year is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearFaster(10, Date);
    cout << "\n09-Subtracting 10 Year is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Subtracting one decade is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecads(10, Date);
    cout << "\n11-Subtracting 10 Decads is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadsFaster(10, Date);
    cout << "\n12-Subtracting 10 Decads is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;





    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13-Subtracting one century is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXCentury(10, Date);
    cout << "\n14-Subtracting 10 century is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXCenturyFaster(10, Date);
    cout << "\n15-Subtracting 10 century is (Faster) : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = DecreaseDateByOneMillnnium(Date);
    cout << "\n16-Subtracting one Millnnium is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}

