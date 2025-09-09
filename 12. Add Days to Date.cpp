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
sDate GetDatFromDayOrderInYear(short AddDay, sDate Date)
{
    short RemainingDays = AddDay+ NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date. Mounth, Date.Year);
    short MonthDays = 0;

    Date.Year = Date.Year;
    Date.Mounth = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMounth(Date.Mounth,Date. Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Mounth++;
            if (Date.Mounth > 12)
            {
                Date.Mounth = 1;
                Date.Year++;
            }
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


sDate ReadFullDate()
{
    sDate Date;
    Date. Year = ReadYear();
   
    Date. Mounth = ReadMounth();
   
    Date. Day = ReadDay();

    return Date;
}


short HowManyDaysToAdd()
{
    short Year;
    cout << "\nEnter How Many days to add " << endl;
    cin >> Year;
    return Year;
}
int main()
{
    sDate Date = ReadFullDate();

    short AddDays = HowManyDaysToAdd();


    Date = GetDatFromDayOrderInYear(AddDays, Date);

    cout << "\nDate after adding [" << AddDays << "] is : ";
    cout << Date.Day << " / " << Date.Mounth << " / " << Date.Year << endl;
    system("pause>0");

}