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
    short Year =ReadYear();

    short Mounth=ReadMounth();

    short Day= ReadDay();

    cout << "Number Of Days from the begning of Year is : " <<
        NumberOfDaysFromTheBeginingOfTheYear(Day, Mounth, Year);
    system("pause>0");

}