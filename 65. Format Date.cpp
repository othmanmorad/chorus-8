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
    cout << "Please enter your string dd/mm/yyy" << endl;
    getline(cin>>ws, S1);
    return S1;
}

vector <string> SpiltString(string S1, string delim)
{
    vector <string>vString;


    
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
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

sDate StringToDate(string DateString)
{
    sDate Date;
    vector <string>vDate;

    vDate = SpiltString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1.replace(pos, StringToReplace.length(), ReplaceTo);

        pos = S1.find(StringToReplace);
    }

    return S1;

}

string FormatDate(sDate Date, string DateFormat = "dd,mm,yyy")
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "yyy", to_string(Date.Year));

    return FormattedDateString;


}

int main()
{
    string DateString = ReadString();

    sDate Date = StringToDate(DateString);

    cout <<"\n\n" << FormatDate(Date) << endl;
    cout << FormatDate(Date, "yyy,dd,mm")<<endl;
    cout << FormatDate(Date, "mm,dd,yyy")<<endl;
    cout << FormatDate(Date, "dd,mm,yyy")<<endl;
    cout << FormatDate(Date, "Day : dd, Month : mm, Year : yyy")<<endl;



    system("pause>0");

}