#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
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
    short Mounth;
    cout << "\nPlease Enter the Mounth " << endl;
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
short NumberOfDaysInMounth( short Mounth,short Year)
{
    short Days[12] = { 31, 28 , 31 , 30 , 31 , 30,31,31,30 ,31 ,30,31 };

    return (Mounth == 2) ? (IsLeapYear(Year)) ? 29 : 28 :
        Days[Mounth - 1];
}
string MounthName(short MounthNumber)
{
    string arrMounths[13] = { " ","Jan", "Feb" , "Mar" , "Apr","May","Jun","Jul" , "Aug" , "Sep" , "Oct" , "Nov" ,"Dec"};

    return (arrMounths[MounthNumber]);

}

void PrintCalenderMounth(short Mounth, short Year)
{

    short current = DayOfWeekOrder(1, Mounth, Year);
    short NumberOfDays = NumberOfDaysInMounth( Mounth,Year);

  

    printf ("\n -------------------%s------------------------\n\n" , MounthName(Mounth).c_str());
    printf( "    Sun   Mon   Tue   Wed   Thu   Fri   Sat  \n" );

    short i;
    for (i = 0;i < current;i++)
        printf("      ");

    for (short j = 1;j <= NumberOfDays;j++)
    {
        printf("%6d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n -------------------------------------------\n");

}

int main()
{
    short Year = ReadYear();
    short Mounth = ReadMounth();
   

    PrintCalenderMounth(Mounth,Year);
   
}