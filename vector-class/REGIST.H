// REGIST.H - Registration class definition
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H

#include <iostream>
#include <string>  // C++ string library
#include <map>

#include "RESULTS.H"
#include "VECTOR.H"

using std::string;
using std::map;
using std::cout;
using std::endl;

    /**
    * @param  const unsigned int MaxResults - The maximum number of results that can be taken in (Global)
    */
const unsigned MaxResults = 10;

    /**
    * @class Registration
    * @brief Handles the Registration information of the student, as well as Unit Information
    *
    * A Registration Class which handles finding information on a specific student, as well as the courses
    * they have done through the Results array.
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
    */

class Registration {
public:
    /**
    * @brief Registration Constructor
    *
    * This is a default construct for the Registration Class
    */
  Registration();
    /**
    * @brief Returns the student name
    *
    * @return const string
    */
  string GetStudentName() const;
    /**
    * @brief Sets the student name
    *
    * @param  string tmpStudentName - The temporary value of the student's name
    * @return void
    */
  void SetStudentName( long tmpStudentName );
    /**
    * @brief Returns the student ID
    *
    * @return const long
    */
  long GetStudentID() const;
    /**
    * @brief Sets the student ID
    *
    * @param  long tmpStudentID - The temporary value of the student's ID
    * @return void
    */
  void SetStudentID( long tmpStudentID );
    /**
    * @brief Returns the student name from a map using a key value
    *
    * @param  long keyVal - The key value of the map (Student ID)
    * @return const string
    */
  string GetStudentName( long keyVal ) const;
    /**
    * @brief Sets the student name using a map
    *
    * @param  long keyVal - The key value of the map (Student ID)
    * @param  string elementVal - The element value to match with the key (Student Name)
    * @return void
    */
  void SetStudentName( long keyVal, string elementVal );
    /**
    * @brief Returns the current semester
    *
    * @return const unsigned int
    */
  unsigned GetSemester() const;
    /**
    * @brief Sets the current semester
    *
    * @param  unsigned tmpSemester - The temporary value of the current semester
    * @return void
    */
  void SetSemester( unsigned tmpSemester );
    /**
    * @brief Returns a results array
    *
    * @return const Results
    */
  const Results& GetResultObj(int index) const;
    /**
    * @brief Sets the array of results
    *
    * @param  Results tmpResults - The temporary array which stores results values
    * @return void
    */
  void SetResultObj( const Results &tmpResults );
    /**
    * @brief Returns the total sum of all the credits of each unit
    *
    * This function gets the sum of each units credits and returns it to the user.
    *
    * @return const unsigned int
    */
  unsigned GetCredits() const;
    /**
    * @brief Returns the count, being the number of units
    *
    * This function gets the number of units a student is enrolled in and returns them.
    *
    * @return const unsigned int
    */
  unsigned GetCount() const;

    /**
    * @brief Sets the total count of units
    *
    * This function sets the total amount of units from a temporary input value.
    *
    * @param  unsigned int cou - The temporary value of total units which is passed in to set the result value
    * @return void
    */
  void SetCount(unsigned cou);
private: //Usually Doxygen comments are NOT added for private variables, but for the sake of learning, they are here
    /**
    * @param  long studentId - An ID number for an individual student
    */
  long studentId;
    /**
    * @param  unsigned semester - The semester in which the units were run
    */
  unsigned semester;
    /**
    * @param  unsigned count - The number of units being shown
    */
  unsigned count;
    /**
    * @param  Results results[] - An array of Unit results and their associated data
    */
  Vector<Results> results;
    /**
    * @param  map<long, string> studentIdentifier - A map to store a Student ID (Key - long), and the associated Student Name (Element - string)
    */
  map<long, string> studentIdentifier;
};

#endif
