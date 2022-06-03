// RESUILTS.CPP - Results class implementation

#include "RESULTS.H"

Results::Results()
{
    inUnit = GetUnit();
    inDate = GetDate();

    marks = 0.0;
}

Results::Results( float tmpMarks, Date tmpDate, Unit tmpUnit )
{
    inUnit = tmpUnit;
    inDate = tmpDate;

    marks = tmpMarks;
}

float Results::GetResults() const
{
    return(marks);
}

void Results::SetResults(float res)
{
    marks = res;
}

const Unit& Results::GetUnit() const
{
    return(inUnit);
}

void Results::SetUnit(const Unit &tmpUnit)
{
    inUnit = tmpUnit;
}

const Date& Results::GetDate() const
{
    return inDate;
}

void Results::SetDate(const Date &tmpDate)
{
    inDate = tmpDate;
}
