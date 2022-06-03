// REGIST.CPP - Registration class implementation.

#include "REGIST.H"

Registration::Registration() //Initial constructor for Registration object
{
    count = 0;
}

long Registration::GetStudentID() const
{
    return studentId;
}

void Registration::SetStudentID( long tmpStudentID )
{
    studentId = tmpStudentID;
}

string Registration::GetStudentName( long keyVal ) const
{
    if(studentIdentifier.find(keyVal) != studentIdentifier.end()) //Checks to see if the Key is in the Map
    {
        return studentIdentifier.at(keyVal); //Returns the value of the map associated with the Key
    }
    else
    {
        cout << "ERROR: Key value " << keyVal << " does not exist" << endl;

        exit(1);
    }
}

void Registration::SetStudentName( long keyVal, string elementVal)
{
    studentIdentifier[keyVal] = elementVal;
}

unsigned Registration::GetSemester() const
{
    return semester;
}

void Registration::SetSemester( unsigned tmpSemester )
{
    semester = tmpSemester;
}

const Results& Registration::GetResultObj(int index) const
{
    return results[index];
}

void Registration::SetResultObj( const Results &tmpResults )
{
    results.SetElement(tmpResults);
}

unsigned Registration::GetCredits() const //Gets the number of Credits from the 'courses' array
{
    unsigned sum = 0; //Sum is used as a temporary variable to return the number of credits

    for(unsigned i = 0; i < count; i++) //Loops through the 'count' (Number of Units)
    {
        sum += results[i].GetUnit().GetCredits(); //Adds up the total number of credits for all units
    }

    return sum;
}

unsigned Registration::GetCount() const
{
    return count;
}

void Registration::SetCount(unsigned cou)
{
    count = cou;
}

/*
*   istream (https://www.cplusplus.com/reference/istream/istream/)
*       - >> Operator (https://www.cplusplus.com/reference/istream/istream/operator%3E%3E/)
*   ostream (https://www.cplusplus.com/reference/ostream/ostream/)
*       - << Operator (https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/)
*/
