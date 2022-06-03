// MAIN.CPP - Case Study, Student Registration

// Count the number of courses taken by the student, calculate total credits
// author KRI
//

#include <iostream>
#include <fstream>

#include "REGIST.H" // Registration class declaration
#include "TOOLS.H" // Tools class declaration

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

///////////////////////////////
// PROTOTYPES
///////////////////////////////
ostream & operator <<( ostream & os, const Registration & R ); //Class Output
istream & operator >>( istream & input, Registration & R ); //Class Input

ostream & operator <<( ostream & os, const Results & R ); //Class Output
istream & operator >>( istream & input, Results & R ); //Class Input

ostream & operator <<( ostream & os, const Unit & U ); //Class Output
istream & operator >>( istream & input, Unit & U ); //Class Input

ostream & operator <<( ostream & os, const Date & D ); //Class Output
istream & operator >>( istream & input, Date & D ); //Class Input

///////////////////////////////
// MAIN FUNCTION
///////////////////////////////

int main()
{
  ifstream infile( "rinput.csv" ); //Tries to open file 'rinput.txt'
  if( !infile ) return -1; //Returns an error if the file is not found

  Registration R; //Creates a Registration object 'R'

  infile >> R; //Takes input from 'rinput.txt'

  ofstream ofile( "routput.txt" ); //Opens the output file 'routput.txt'

// Use a debugger and track down the calls made "behind the scene"
  ofile << R
    << "Number of courses = " << R.GetCount() << '\n'
    << "Total credits     = " << R.GetCredits() << '\n';

  // Declare and initialize a Course, and modify
  // its credits.

  Unit aUnit( "IT Project Managment", "ICT201", 3, "David Tenant", "250.3.023", "ict201@murdoch.edu.au", "+61 8 9225 7585" );
  cout << aUnit; // the operator << for Course is called

  return 0;
}

///////////////////////////////
// REGISTRATION I/O
///////////////////////////////

istream & operator >>( istream & input, Registration & R )
{
    std::string tmpStr; //Stores a temporary string value - TEMPORARY, USED FOR SET METHOD ONLY

    unsigned tmpCount; // number of courses - TEMPORARY, USED FOR SET METHOD ONLY

    Results tmpResults; // A temporary result container - TEMPORARY, USED FOR SET METHOD ONLY

    getline(input, tmpStr, ','); //Gets the Student ID
    R.SetStudentID(std::stoi(tmpStr));

    getline(input, tmpStr, ','); //Gets the Student Name
    R.SetStudentName(R.GetStudentID(), tmpStr);

    getline(input, tmpStr, ','); //Gets the semester number
    R.SetSemester(std::stoi(tmpStr));

    input >> tmpCount;

    for(unsigned i = 0; i < tmpCount; i++)
    {
        input >> tmpResults;  // track down which >> operator is called. Hint: look at what is being input.

        R.SetResultObj(tmpResults);
    }

    R.SetCount(tmpCount);

    return input;
}

ostream & operator <<( ostream & os, const Registration & R )
{
    os << "Student ID: " << R.GetStudentID() << '\n'
       << "Student Name: " << R.GetStudentName(R.GetStudentID()) << '\n'
       << "Semester: " << R.GetSemester() << '\n';

    for(unsigned i = 0; i < R.GetCount(); i++)
    {
        os << R.GetResultObj(i) << '\n';
    }

    return os;
}

///////////////////////////////
// RESULTS I/O
///////////////////////////////

istream & operator >>( istream & input, Results & R )
{
    std::string tmpStr; //Stores a temporary string value - TEMPORARY, USED FOR SET METHOD ONLY

    Unit tmpUnit; //Temporary Unit object - TEMPORARY, USED FOR SET METHOD ONLY
    Date tmpDate; //Temporary Date object - TEMPORARY, USED FOR SET METHOD ONLY

    input >> tmpUnit;

    getline(input, tmpStr, ',');

    input >> tmpDate;

    R.SetUnit(tmpUnit);
    R.SetResults(std::stof(tmpStr));
    R.SetDate(tmpDate);

    return input;
}

ostream & operator <<( ostream & os, const Results & R )
{
  os << R.GetUnit() << "  Marks: " << R.GetResults() << '\n'
  << R.GetDate();

  return os;
}

///////////////////////////////
// UNIT I/O
///////////////////////////////

istream & operator >>( istream & input, Unit & U )
{
  std::string tmpStr; //Stores a temporary string value - TEMPORARY, USED FOR SET METHOD ONLY

  getline(input, tmpStr, '\n'); //Catches the New Line before the Unit Name

  getline(input, tmpStr, ','); //Gets the name of the Unit
  U.SetName(tmpStr);

  getline(input, tmpStr, ','); //Gets the ID of the Unit
  U.SetUnitID(tmpStr);

  getline(input, tmpStr, ','); //Gets the credits for the Unit
  U.SetCredits(std::stoi(tmpStr));

  getline(input, tmpStr, ','); //Gets the unit coordinators name
  U.SetCoordName(tmpStr);

  getline(input, tmpStr, ','); //Gets the unit coordinators room number
  U.SetCoordRoomNum(tmpStr);

  getline(input, tmpStr, ','); //Gets the unit coordinators email address
  U.SetCoordEmail(tmpStr);

  getline(input, tmpStr, ','); //Gets the unit coordinators phone number
  U.SetCoordPhoneNum(tmpStr);

  return input;
}

ostream & operator <<( ostream & os, const Unit & U )
{
  os << "  Unit ID: " << U.GetUnitID() << '\n'
     << "  Unit Name: " << U.GetName() << '\n'
     << "  Credits: " << U.GetCredits() << '\n'
     << "  -----------------------------------------" << '\n'
     << "  Coordinator Name: " << U.GetCoordName() << '\n'
     << "  Coordinator Room: " << U.GetCoordRoomNum() << '\n'
     << "  Coordinator Email: " << U.GetCoordEmail() << '\n'
     << "  Coordinator Phone: " << U.GetCoordPhoneNum() << '\n'
     << "  -----------------------------------------" << '\n';

  return os;
}

///////////////////////////////
// DATE I/O
///////////////////////////////
istream & operator >>( istream & input, Date & D )
{
    std::string tmpStr; //Stores a temporary string value - TEMPORARY, USED FOR SET METHOD ONLY

    unsigned tmpYear; //Stores a Year value (Year that the result was set) - TEMPORARY, USED FOR SET METHOD ONLY

    getline(input, tmpStr, ','); //Gets the day from file
    D.SetDay(std::stoi(tmpStr));

    getline(input, tmpStr, ','); //Gets the month from file
    D.SetMonth(std::stoi(tmpStr)); //Sets it to be formatted as a number

    input >> tmpYear; //Gets the year from file
    D.SetYear(tmpYear);

    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    Tools tmpTools; //Temporary tools object

    tmpTools.SetMonthFormatted(D.GetMonth()); //Sets it to be formatted into a string (E.g. May, June, etc.)

    os << "  Date: " << D.GetDay() << " "
       << tmpTools.GetMonthFormatted() << " "
       << D.GetYear() << '\n';

    return os;
}
