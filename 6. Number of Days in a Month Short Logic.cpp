#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
    short Year;
    cout << "\nEnter the year to check it" << endl;
    cin >> Year;
    return Year;
}

short ReadMounth()
{
    short Mounth;
    cout << "\nPlease Enter the Mounth to check it" << endl;
    cin >> Mounth;
    return Mounth;
}


bool IsLeapYear(int Year)
{

    {
        return  (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
    }

}

short NumberOfDaysInMounth(short Year, short Mounth)
{
    if (Mounth < 1 || Mounth>12)
    {
        return 0;
    }

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    
    return (Mounth == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Mounth - 1];

}


short NumberOfHoursInMounth(short Year, short Mounth)
{
    return   NumberOfDaysInMounth(Year, Mounth) * 24;
}

int NumberOfMinutesInMinutes(short Year, short Mounth)
{
    return  NumberOfHoursInMounth(Year, Mounth) * 60;
}

int NumberOfSecondsInMounth(short Year, short Mounth)
{
    return  NumberOfMinutesInMinutes(Year, Mounth) * 60;
}




int main()
{
    short Year = ReadYear();
    short Mounth = ReadMounth();

    cout << "\nNumber of Days      in Mounth[" << Mounth << "] is " << NumberOfDaysInMounth(Year, Mounth) << endl;
    cout << "\nNumber of Hours     in Mounth[" << Mounth << "] is " << NumberOfHoursInMounth(Year, Mounth) << endl;
    cout << "\nNumber of Minutes   in Mounth[" << Mounth << "] is " << NumberOfMinutesInMinutes(Year, Mounth) << endl;
    cout << "\nNumber of  Seconds  in Mounth[" << Mounth << "] is " << NumberOfSecondsInMounth(Year, Mounth) << endl;


}
