#include <iostream>
#include <string>

using namespace std;
struct sDate
{
    short Year;
    short Mounth;
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

    Date.Mounth = ReadMounth();

    Date.Day = ReadDay();

    return Date;
}

bool IsDate1LessThanDate2(sDate Date , sDate Date2)
{
   return (Date.Year<Date2.Year) ? true :
          ((Date.Year==Date2.Year)?(Date.Mounth<Date2.Mounth ? true :
          (Date.Mounth == Date2.Mounth ? Date.Day < Date2.Day : false)) : false);


}


int main()
{
    sDate Date  = ReadFullDate();
    cout << "\n\n\n" << endl;
    sDate Date2 = ReadFullDate();
   
    if (IsDate1LessThanDate2(Date, Date2))
    {
        cout << "\nYes Date 1 less than date 2";
    }
    else
    {
        cout << "\nNo Date 1 not less than date 2";
    }


    system("pause>0");

}