#include <cassert>
#include <iostream>

// Return the number of days in a specific month/year.
int getDaysInMonth(int month, int year);
bool isLeapYear(int year);

int main()
{
    // 0 - Monday, 1 - Tuesday, ... , 6 - Sunday
    int dayOfWeek = 0;

    int sum = 0;
    for (int year = 1901; year <= 2000; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            // Increase sum if the first day of the month is Sunday.
            if (dayOfWeek == 6)
                sum++;
            // Goto the next month.
            dayOfWeek = (dayOfWeek + getDaysInMonth(month, year)) % 7;
        }
    }

    std::cout << sum << '\n';
}

int getDaysInMonth(int month, int year)
{
    const char daysInMonths[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    assert(month >= 0 && month < 12);

    // Check for a leap year.
    if (month == 1 && isLeapYear(year))
        return 29;
    else
        return daysInMonths[month];
}

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
