#include <iostream>
#include <string>
using namespace std;

int ReadYear()
{
    int Year;
    cout << "\nEnter the year to check it" << endl;
    cin >> Year;
    return Year;
}

bool IsLeapYear(int Year)
{

    {
        return  (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
    }

}

short CalucletDaysInYear(int Year)
{
   return IsLeapYear(Year) ? 366 : 365;
    
}

short CalucletHoursInYear(int Year)
{
    return  CalucletDaysInYear(Year) * 24;
}

int CalucletMinutesInYear(int Year)
{
    return  CalucletHoursInYear(Year) * 60;
}

int CalucletSecondsInYear(int Year)
{
    return  CalucletMinutesInYear(Year) * 60;
}


    

int main()
{
    int Year = ReadYear();
   
   
   
   


   
       cout << "\nNumber of Days      in year[" << Year << "] is "<< CalucletDaysInYear(Year)<<endl;
       cout << "\nNumber of Hours     in year[" << Year << "] is "<< CalucletHoursInYear(Year) << endl;
       cout << "\nNumber of Minutes   in year[" << Year << "] is "<< CalucletMinutesInYear(Year)<<endl;
       cout << "\nNumber of  Seconds  in year[" << Year << "] is " << CalucletSecondsInYear(Year) << endl;
 

}
