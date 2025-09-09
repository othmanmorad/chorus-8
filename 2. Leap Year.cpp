#include <iostream>
#include <string>
using namespace std;

int ReadYear()
{
    int Year;
    cout << "\nEnter the year to check it"<<endl;
    cin >> Year;
    return Year;
}

bool IsLeapYear(int Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 ==0)
    {
        return false;
    }
    
    else if (Year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
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
            cout << "\nYes "<< Year <<" is a leap year";
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

