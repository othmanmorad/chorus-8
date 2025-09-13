#include<iostream>
#include<string>

using namespace std;


//problem17

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


bool IsDate1BeforDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}


void SwapDates(sDate& Date1, sDate& Date2)
{
    sDate Temp ;

    Temp.Day = Date1.Day;
    Temp.Month = Date1.Month;
    Temp.Year = Date1.Year;


    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;


    Date2.Day = Temp.Day;
    Date2.Month = Temp.Month;
    Date2.Year = Temp.Year;

}



int GetDiffrinceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }
    {

        while (IsDate1BeforDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaceDateByOneDay(Date1);

        }
        return IncludeEndDay ? ++Days *SwapFlagValue : Days*SwapFlagValue;

    }
   
     
}

int main()
{

    sDate Date1 = ReadFullDate();
    cout << "\n\n";
    sDate Date2 = ReadFullDate();

    cout << "\n\n" << endl;

    cout << "Difference is : " << GetDiffrinceInDays(Date1, Date2) << " Day(s)" << endl;
    cout << "Difference (include End Day) is : " << GetDiffrinceInDays(Date1, Date2, true) << " Day(s)";


}