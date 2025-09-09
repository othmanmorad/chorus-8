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
        return  (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0 );
    }
    
}

void AddMore()
{

    char AddMore = 'y';

    do
    {
        int Year = ReadYear();
        if (IsLeapYear(Year))
        {
            cout << "\nYes " << Year << " is a leap year";
        }
        else
        {
            cout << "\nNo " << Year << " is not a leap year";
        }

        cout << "\nMore year ? (Y/N) " << endl;
        cin >> AddMore;
    } while (AddMore == 'y' || AddMore == 'Y');
}

int main()
{
    AddMore();
}
