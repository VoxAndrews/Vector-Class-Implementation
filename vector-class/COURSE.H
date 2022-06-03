// COURSE.H - Course class definition
// author KRI
// modified smr

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>  // C++ string library

using namespace std;

    /**
    * @param  const unsigned int CourseNameSize - The maximum size of the Course Name (Global)
    */
const unsigned CourseNameSize = 10;

    /**
    * @class Course
    * @brief Handles information on a student's individual course
    *
    * A Class which handles all of the information for an individual course, ready to be sent to
    * REGIST.CPP.
    *
    * @author KRI
    * @version 01
    *
    * @author smr
    * @version 02
    *
    * @author Darcy Lyndon Cukrov Wilson
    * @version 03
    * @date 21/03/2022 Darcy Lyndon Cukrov Wilson
    *
    * @todo Depricated by 'UNIT.CPP' and 'UNIT.H'
    */

class Course {
public:
  Course();
  Course( std::string nam, char sect, unsigned cred );
  // Construct a course from a name, section letter,
  // and number of credits.

  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned cred );
  // Set the number of credits.

  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream & os, const Course & C );
  friend istream & operator >>( istream & input, Course & C );

private:
  std::string name;  // course name
  char section;   // section (letter) can be enrolment mode
  int  credits;   // number of credits
};

#endif
