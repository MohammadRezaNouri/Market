#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    void setYear(int);
    int getYear() const;
    void setMonth(int);
    int getMonth() const;
    void setDay(int);
    int getDay() const;
    void setHour(int);
    int getHour() const;
    void setMinute(int);
    int getMinute() const;
    void setDate(string);
    string getDate() const;

private:
    int day, month, year, hour, minute;
};

#endif