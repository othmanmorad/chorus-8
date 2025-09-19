#include <iostream>
#include <string>
using namespace std;




//problem 60
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
int main()
{
    cout << "\nEnter period : \n";
    sPeriod Period = ReadPeriod();

    cout << "\nEnter Date to check \n";
    sDate DateToCheck = ReadFullDate();


    if (IsDayInPeriod(DateToCheck, Period))
    {
        cout << "Yes,Date is within Period";
    }
    else
    {
        cout << "No,Date Not within Period";
    }
}