#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct sDate
{
    short Day;
    short Month;
    short Year;

};
string ReadString()
{
    string S1;
    cout << "Please enter your string " << endl;
    getline(cin, S1);
    return S1;
}

vector <string> SpiltString(string S1, string delim)
{
    vector <string>vString;


    cout << "\nYour string words are: \n\n";
    short  pos = 0;
    string sWord;


    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}


string DateToString(sDate Date)
{
    return to_string (Date.Day) + "/" +to_string( Date.Month )+ "/" + to_string(Date.Year);
}

sDate StringToDate(string DateString)
{
    sDate Date;
    vector <string>vDate;

    vDate= SpiltString(DateString, "/");

    Date.Day   = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year  = stoi(vDate[2]);

    return Date;
}



int main()
{
    string DateString = ReadString();
   
    sDate Date = StringToDate(DateString);

    cout << "\nDay " << Date.Day << endl;
    cout << "Month " << Date.Month << endl;
    cout << "Year " << Date.Year << endl;

    cout <<"\nYou Enterd " << DateToString(Date);
    system("pause>0");

}