#include "Date.h"

#include <ctime>

void Date::setDate(string Date)
{
    int temp = stoi(Date.substr(0, 4));
    if (temp >= 2019 && temp <= 2021) //تاریخ انقضا بیشتر از 2 سال نداریم و قدیمی ترین تاریخ تولید هم برای 1 سال پیش است
        year = temp;
    else
        throw invalid_argument("The number of years is wrong.(2019 - 2021)");
    temp = stoi(Date.substr(5, 7));
    if (temp < 13 && temp > 0)
        month = temp;
    else
        throw invalid_argument("The number of months is wrong.(1 - 12)");
    temp = stoi(Date.substr(8, 10));
    if (month == 4 || month == 6 || month == 9)
        if (temp < 31 && temp > 0)
            day = temp;
        else
            throw invalid_argument("The number of days for months 4, 6, 9 is wrong.(1 - 30)");
    else if (month == 2)
        if (temp < 29 && temp > 0)
            day = temp;
        else
            throw invalid_argument("The number of days for month 2 is wrong.(1 - 28)");
    else
        if (temp < 32 && temp > 0)
            day = temp;
        else
            throw invalid_argument("The number of days for months 1, 3, 5, 7, 8, 10, 12 is wrong.(1 - 31)");
    temp = stoi(Date.substr(11, 13));
    if (temp < 24 && temp > -1)
        hour = temp;
    else
        throw invalid_argument("The number of hours is wrong.(0 - 23)");
    temp = stoi(Date.substr(14, 16));
    if (temp < 60 && temp > -1)
        minute = temp;
    else
        throw invalid_argument("The number of minutes is wrong.(0 - 59)");
}

string Date::getDate() const
{
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day) + " " + to_string(hour) + ":" + to_string(minute);
}

void Date::setYear(int Year)
{
    if (Year > 2018 && Year < 2022) //تاریخ انقضا بیشتر از 2 سال نداریم و قدیمی ترین تاریخ تولید هم برای 1 سال پیش است
        year = Year;
    else
        throw invalid_argument("The number of years is wrong.(2019 - 2021)");
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int Month)
{
    if (Month < 13 && Month > 0)
        month = Month;
    else
        throw invalid_argument("The number of months is wrong.(1 - 12)");
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int Day)
{
    if (Day == 4 || Day == 6 || Day == 9)
        if (Day < 31 && Day > 0)
            day = Day;
        else
            throw invalid_argument("The number of days for months 4, 6, 9 is wrong.(1 - 30)");
    else if (Day == 2)
        if (Day < 29 && Day > 0)
            day = Day;
        else
            throw invalid_argument("The number of days for month 2 is wrong.(1 - 28)");
    else
        if (Day < 32 && Day > 0)
            day = Day;
        else
            throw invalid_argument("The number of days for months 1, 3, 5, 7, 8, 10, 12 is wrong.(1 - 31)");
}

int Date::getDay() const
{
    return day;
}

void Date::setHour(int Hour)
{
    if (Hour < 24 && Hour > -1)
        hour = Hour;
    else
        throw invalid_argument("The number of hours is wrong.(0 - 23)");
}

int Date::getHour() const
{
    return hour;
}

void Date::setMinute(int Minute)
{
    if (Minute < 60 && Minute > -1)
        minute = Minute;
    else
        throw invalid_argument("The number of minutes is wrong.(0 - 59)");
}

int Date::getMinute() const
{
    return minute;
}