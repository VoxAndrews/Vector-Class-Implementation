// DATE.CPP - Date class implementation

#include "DATE.H"

Date::Date()
{
    day = 22;
    month = 5;
    year = 1998;
}

Date::Date( unsigned tmpDay, unsigned tmpMonth, unsigned tmpYear )
{
    day = tmpDay;
    month = tmpMonth;
    year = tmpYear;
}

unsigned Date::GetDay() const
{
    return day;
}

void Date::SetDay( unsigned tmpDay )
{
    day = tmpDay;
}

unsigned Date::GetMonth() const
{
    return month;
}

void Date::SetMonth( unsigned tmpMonth )
{
    month = tmpMonth;
}

unsigned Date::GetYear() const
{
    return year;
}

void Date::SetYear( unsigned tmpYear )
{
    year = tmpYear;
}
