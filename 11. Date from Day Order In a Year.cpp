#include<iostream>
#include<string>
using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short NumberOfDaysInMounth(short Mounth, short Year)
{
    short Days[12] = { 31, 28 , 31 , 30 , 31 , 30,31,31,30 ,31 ,30,31 };

    return (Mounth == 2) ? (IsLeapYear(Year)) ? 29 : 28 :
        Days[Mounth - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Mounth, short Year)
{
    short TotalDays = 0;

    for (short i = 1;i <= Mounth - 1;i++)
    {
        TotalDays += NumberOfDaysInMounth(i, Year);
    }
    TotalDays += Day;

    return TotalDays;
}

struct sDate
{
        short Year;
        short Mounth;
        short Day;
};
sDate GetDatFromDayOrderInYear(short DayOrderINYear, short Year)
{
    sDate Date;
    short RemainingDays = DayOrderINYear;
    short MonthDays=0;

    Date.Year = Year;
    Date.Mounth = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMounth(Date.Mounth, Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Mounth++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
short ReadYear()
{
    short Year;
    cout << "\nEnter the year " << endl;
    cin >> Year;
    return Year;
}

short ReadMounth()
{
    short Year;
    cout << "\nEnter the Mounth " << endl;
    cin >> Year;
    return Year;
}

short ReadDay()
{
    short Year;
    cout << "\nEnter the day " << endl;
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();

    short Mounth = ReadMounth();

    short Day = ReadDay();

    short DayOrderINYear= NumberOfDaysFromTheBeginingOfTheYear(Day, Mounth, Year);

    cout << "Number Of Days from the begning of Year is : " << DayOrderINYear << endl;
       
    sDate Date;

   Date= GetDatFromDayOrderInYear(DayOrderINYear, Year);

   cout << "\nDate for [" << DayOrderINYear << "] is : ";
   cout << Date.Day << " / " << Date.Mounth << " / " << Date.Year << endl;
    system("pause>0");

}