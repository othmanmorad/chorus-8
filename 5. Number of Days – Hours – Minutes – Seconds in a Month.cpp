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

    if (Mounth == 2)
    {
        return IsLeapYear(Year)  ? 29 : 28;
    }

    //Method1
   // else  if (Mounth == 1 || Mounth == 3 || Mounth == 5 || Mounth == 7 || Mounth == 8 || Mounth == 10 || Mounth == 12)
   // {
   //     return 31;
   // }


    //Method2
    short arr31Days[7] = { 1,3,5,7,8,10,12 };
    for (short i = 0;i <= 7;i++)
    {
        if (arr31Days[i - 1] == Mounth)
        {
            return 31;
        }
    }

   
    
        return 30;
    
}


short NumberOfHoursInMounth(short Year , short Mounth)
{
    return   NumberOfDaysInMounth( Year, Mounth) * 24;
}

int NumberOfMinutesInMinutes(short Year, short Mounth)
{
    return  NumberOfHoursInMounth(Year,Mounth) * 60;
}

int NumberOfSecondsInMounth(short Year,short Mounth)
{
    return  NumberOfMinutesInMinutes(Year,Mounth) * 60;
}




int main()
{
    short Year = ReadYear();
    short Mounth = ReadMounth();

    cout << "\nNumber of Days      in Mounth[" << Mounth << "] is " << NumberOfDaysInMounth(Year,Mounth) << endl;
    cout << "\nNumber of Hours     in Mounth[" << Mounth << "] is " << NumberOfHoursInMounth(Year,Mounth) << endl;
    cout << "\nNumber of Minutes   in Mounth[" << Mounth << "] is " << NumberOfMinutesInMinutes(Year,Mounth) << endl;
    cout << "\nNumber of  Seconds  in Mounth[" << Mounth << "] is " << NumberOfSecondsInMounth(Year,Mounth) << endl;


}
