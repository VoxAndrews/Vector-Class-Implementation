// COURSE.CPP - Course class implementation

#include "course.h"

Course::Course() //Default constructor for the Course class
{
  name[0] = '\0'; // it is a char * string, not a C++ string object.
}

Course::Course(std::string nam, char sect, unsigned cred) //A constructor used to initialise the Course class based on an input
{
  name = nam;
  section = sect;
  credits = cred;
}

unsigned Course::GetCredits() const
{
  return credits;
}

void Course::SetCredits( unsigned cred )
{
  credits = cred;
}

istream & operator >>( istream & input, Course & C )
{
  input >> C.name >> C.section >> C.credits;
  return input;
}

ostream & operator <<( ostream & os, const Course & C )
{
  os << "  Course:  " << C.name << '\n'
     << "  Section: " << C.section << '\n'
     << "  Credits: " << C.credits << '\n';
  return os;
}
