#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
    short Year;
    cout << "\nEnter the year you born" << endl;
    cin >> Year;
    return Year;
}

short ReadMounth()
{
    short Mounth;
    cout << "\nPlease Enter the Mounth you born" << endl;
    cin >> Mounth;
    return Mounth;
}

short ReadDay()
{
    short Mounth;
    cout << "\nPlease Enter the day you born" << endl;
    cin >> Mounth;
    return Mounth;
}

short DayOfWeekOrder(short Day, short Mounth, short Year)
{
    short a = (14 - Mounth) / 12;
    short y = Year - a;
    short m = Mounth + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short DayOfWeekOrder)
{
    string arr[7] = { "Sun" , "Mon" , "Tue" ,"Wed" ,"The","Fri","Sat" };
    return arr[DayOfWeekOrder];
}

int main()
{
    short Day = ReadDay();
    short Mounth = ReadMounth();
    short Year = ReadYear();

    cout << "\nDate : " << Day << " / " << Mounth << " / " << Year << endl;

    cout << "\nDay Order : " << DayOfWeekOrder(Day, Mounth, Year) << endl;
    cout << "\nDay Name : " << DayName(DayOfWeekOrder(Day, Mounth, Year)) << endl;
}