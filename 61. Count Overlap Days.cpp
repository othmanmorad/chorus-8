#include <iostream>
#include <string>
using namespace std;




//problem61
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



bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}



bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ?
        ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day)
            ? true : false) : false) : false;

}



bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}


enum enDateCompare { Befor = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforDate2(Date1, Date2)) return enDateCompare::Befor;
    if (IsDate1AfterDate2(Date1, Date2)) return enDateCompare::After;

    // if (IsDate1EqualDate2(Date1, Date2)) return enDateCompare::Equal;

     //faster
    return enDateCompare::Equal;
}



bool IsDayInPeriod(sDate DateToCheck, sPeriod Period)
{

    return !(

        CompareDates(DateToCheck, Period.StartDate) == enDateCompare::Befor ||
        CompareDates(DateToCheck, Period.EndDate) == enDateCompare::After


        );
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


bool IsOverLapDate(sPeriod Period1, sPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Befor ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true;

}




int CountOverLapDays(sPeriod Period1, sPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int countOverLapDays = 0;

    if (!IsOverLapDate(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {

        while (IsDate1BeforDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDayInPeriod(Period1.StartDate, Period2))

                countOverLapDays++;

            Period1.StartDate = IncreaceDateByOneDay(Period1.StartDate);

        }
    }

    else
    {
        while (IsDate1BeforDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDayInPeriod(Period2.StartDate, Period1))

                countOverLapDays++;

            Period2.StartDate = IncreaceDateByOneDay(Period2.StartDate);


        }
    }
    return countOverLapDays;

}
int main()
{
    cout << "\nEnter period 1 \n";
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter period 2 \n";
    sPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days count is : ";
    cout << CountOverLapDays(Period1, Period2);
}







