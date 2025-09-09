#include <iostream>
#include <string>

using namespace std;
struct sDate
{
    short Year;
    short Month;
    short Day;
};

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
    Date.Year = ReadYear();

    Date.Month = ReadMounth();

    Date.Day = ReadDay();

    return Date;
}

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

bool IsLastMonthInYear(short Month)
{

    return(Month == 12);

}


bool IsLastDayInMonth(sDate Date)
{
    return(Date.Day == NumberOfDaysInMounth(Date.Month, Date.Year));


}





sDate IncreaseDateByOneDay(sDate Date)
{
    
    if (IsLastDayInMonth(Date))
    {
        

        if (IsLastMonthInYear(Date.Month))

        {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
           
        }

        else
        {
            Date.Month++;
            Date.Day = 1;
            
        }


    }

    else
    {
        Date.Day++;
    }
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    cout << "\n\n\n" << endl;

    cout<<"\nDate after adding one day is : ";
    Date=IncreaseDateByOneDay(Date);
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    system("pause>0");

}