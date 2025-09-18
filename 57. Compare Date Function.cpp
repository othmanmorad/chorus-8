#include <iostream>
#include <string>
using namespace std;





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

/*
short CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforDate2(Date1, Date2)) return -1;
    if (IsDate1EqualDate2(Date1, Date2)) return 0;
    else
        return 1;
}  */

// Method 2
enum enDateCompare { Befor = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforDate2(Date1, Date2)) return enDateCompare::Befor;
    if (IsDate1AfterDate2(Date1, Date2)) return enDateCompare::After;

    // if (IsDate1EqualDate2(Date1, Date2)) return enDateCompare::Equal;

     //faster
    return enDateCompare::Equal;
}

int main()
{
    cout << "\nEnter Date 1\n";
    sDate Date1 = ReadFullDate();


    cout << "\n\n\nEnter Date2\n";
    sDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2);
}